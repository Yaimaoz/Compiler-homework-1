#pragma once
#include "Gate.hpp"
#include <cstring>
#include <iterator>
#include <list>
#include <map>
#include <string>
typedef std::map< std::string, Gate* > GateMap;

class Network {

public:
    Gate start;
    Gate end;
    GateList poList;
    GateMap gatePool;
    GateList topologySequence;
    std::map< int, GateList > levelTable;

    Network();
    ~Network();
    void parser(std::string filename);
    void gateWiring(std::list< char* >&);
    void printGraph();
    void resetFanOutIt();
    void topologySort();
    void evalNetwork();
    void breadthFirstSearch();
    void printLevel();
    void test();
};
