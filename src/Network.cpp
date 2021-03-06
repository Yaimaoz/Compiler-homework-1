#include "Network.hpp"
#include <fstream>
using std::cout;
using std::endl;
using std::cin;
Network::Network()
{
    start.name = "start";
    end.name = "end";
}

Network::~Network()
{
    for (auto gate : gatePool)
        delete gate.second;
}

void Network::parser(std::string filename)
{
    std::ifstream infile(filename, std::ios::in);
    char delims[] = " ,=()";
    std::string line;
    while (std::getline(infile, line)) {
        if (!line.size())
            continue;
        if (line[0] == '#')
            continue;
        std::list< char* > tokens;
        char* cline = strdup(line.c_str());
        char* tok = strtok(cline, delims);
        while (tok) {
            tokens.push_back(tok);
            tok = strtok(NULL, delims);
        };
        gateWiring(tokens);

        delete[] cline;
        line.clear();
    }
    infile.close();

    start.fanOutIt = start.fanouts.begin();
    for (auto pair : gatePool) {
        if (!pair.second->fanouts.size())
            end.fanins.push_back(pair.second);
    }
    resetFanOutIt();
    
    GateSet temp;
    for ( auto input : start.fanouts )
        temp.insert(input);
    levelTable[0] = temp;
}

void Network::gateWiring(std::list< char* >& tokens)
{

    // NONE, BUFFER, AND, OR, NOT, NAND, NOR, XOR, NXOR, INPUT, OUTPUT
    if (!strcmp(tokens.front(), "INPUT")) {
        Gate* buffer = new Gate;
        buffer->level = 0;
        buffer->name = tokens.back();
        buffer->type = INPUT;
        buffer->fanins.push_back(&start);
        start.fanouts.push_back(buffer);
        gatePool[tokens.back()] = buffer;
    }
    else if (!strcmp(tokens.front(), "OUTPUT")) {
        return;
    }
    else {
        std::map< std::string, Gate* >::iterator it = gatePool.find(tokens.front());
        if (it == gatePool.end()) {
            Gate* buffer1 = new Gate;
            buffer1->name = tokens.front();
            gatePool[tokens.front()] = buffer1;
        }

        if (tokens.size() == 3) {
            gatePool[tokens.front()]->type = (!strcmp(*std::next(tokens.begin()), "BUFF")) ? BUFFER : NOT;
        }
        else {
            if (!strcmp(*std::next(tokens.begin()), "OR")) {
                gatePool[tokens.front()]->type = OR;
            }
            else if (!strcmp(*std::next(tokens.begin()), "AND")) {
                gatePool[tokens.front()]->type = AND;
            }
            else if (!strcmp(*std::next(tokens.begin()), "NAND")) {
                gatePool[tokens.front()]->type = NAND;
            }
            else if (!strcmp(*std::next(tokens.begin()), "NOR")) {
                gatePool[tokens.front()]->type = NOR;
            }
            else if (!strcmp(*std::next(tokens.begin()), "XOR")) {
                gatePool[tokens.front()]->type = XOR;
            }
            else if (!strcmp(*std::next(tokens.begin()), "NXOR")) {
                gatePool[tokens.front()]->type = NXOR;
            }
            
            it = gatePool.find(*std::next(tokens.rbegin()));
            if (it == gatePool.end()) {
                Gate* buffer2 = new Gate;
                buffer2->name = tokens.back();
                gatePool[*std::next(tokens.rbegin())] = buffer2;
            }
            gatePool[tokens.front()]->fanins.push_back(gatePool[*std::next(tokens.rbegin())]);
            gatePool[*std::next(tokens.rbegin())]->fanouts.push_back(gatePool[tokens.front()]);
        }

        it = gatePool.find(tokens.back());
        if (it == gatePool.end()) {
            Gate* buffer2 = new Gate;
            buffer2->name = tokens.back();
            gatePool[tokens.back()] = buffer2;
        }
        gatePool[tokens.front()]->fanins.push_back(gatePool[tokens.back()]);
        gatePool[tokens.back()]->fanouts.push_back(gatePool[tokens.front()]);
    }

}

void Network::resetFanOutIt()
{

    for (auto gate : gatePool) {
        gate.second->fanOutIt = gate.second->fanouts.begin();
        gate.second->isTrav = false;
    }
}

void Network::topologySort()
{

    GateList stack;
    stack.push_back(&start);
    start.isTrav = true;
    while (stack.size()) {
        if (stack.back()->fanOutIt == stack.back()->fanouts.end()) {
            topologySequence.push_front(stack.back());
            stack.pop_back();
        }
        else {
            if (!(*stack.back()->fanOutIt)->isTrav) {
                stack.push_back(*(stack.back()->fanOutIt++));
                stack.back()->isTrav = true;
            }
            else {
                ++stack.back()->fanOutIt;
            }
        }
    }
    topologySequence.pop_front();
    resetFanOutIt();
}

void Network::evalNetwork()
{
    for (auto gate : topologySequence)
        gate->eval();
}

void Network::evalLevel()
{
    int PrimaryOutput = 0;
    for (auto gate : topologySequence) {
        if (gate->type != INPUT) {
            int max = gate->fanins.front()->level;
            for (auto g : gate->fanins) {
                if (g->level > max)
                    max = g->level;
            }
            gate->level = max + 1;
            if ( PrimaryOutput < gate->level )
                PrimaryOutput = gate->level;
            auto it = levelTable.find(gate->level);
            if (it != levelTable.end()) {
                it->second.insert(gate);
            }
            else {
                GateSet setTemp;
                setTemp.insert(gate);
                levelTable[gate->level] = setTemp;
            }
        }
    }
    for ( auto gate : topologySequence ){
        if ( gate->fanouts.size() == 0 ) {
            if ( levelTable[PrimaryOutput].find(gate) == levelTable[PrimaryOutput].end() ){
                levelTable[PrimaryOutput].insert(gate);
                levelTable[gate->level].erase(gate);
                gate->level = PrimaryOutput;
            }
        }
    } 
}

void Network::test()
{

    for (auto gate : start.fanouts)
        gate->value = 0;
    evalNetwork();
    for (auto gate : end.fanins)
        cout << gate->value;
    cout << endl;

    for (auto gate : start.fanouts)
        gate->value = 1;
    evalNetwork();
    for (auto gate : end.fanins)
        cout << gate->value;
    cout << endl;
}

void Network::printGraph()
{
    for (auto& pair : gatePool) {
        cout << "gate name: " << pair.first << endl;
        cout << "gate type: " << pair.second->type << endl;
        cout << "gate level: " << pair.second->level << endl;
        cout << "gate fanins: ";
        for (auto fanin : pair.second->fanins)
            cout << fanin->name << " ";
        cout << endl;
        cout << "gate fanouts: ";
        for (auto fanout : pair.second->fanouts)
            cout << fanout->name << " ";
        cout << endl;
        cout << "~~~~~~~~\n";
    }
}

void Network::printLevel()
{
    cout << levelTable.size()  << endl;
    for (auto& temp : levelTable) {
        cout << "Level: " << temp.first << endl;
        for (auto g : temp.second)
            cout << g->name << ", ";
        cout << endl;
    }
}
