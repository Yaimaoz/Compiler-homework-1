#pragma once
#include "Gate.hpp"
#include <cstring>
#include <iterator>
#include <list>
#include <map>
#include <string>
#include <set>
typedef std::map< std::string, Gate* > GateMap;
typedef std::set< Gate* > GateSet;

class Network {

public:
    Gate start;
    Gate end;
    GateList poList;
    GateMap gatePool;
    GateList topologySequence;
    std::map< int, GateSet > levelTable;

    Network();
    ~Network();
    void parser(std::string filename);
    void gateWiring(std::list< char* >&);
    void printGraph();
    void resetFanOutIt();
    void topologySort();
    void evalNetwork();
    void evalLevel();
    void breadthFirstSearch();
    void printLevel();
    void test();
};
