#pragma once
#include"Gate.h"
#include<map>
#include<string>
#include<cstring>
#include<list>
#include<iterator>
typedef std::map<std::string, Gate*> GateMap;

class Network{

    private:
        Gate start;
        Gate end;
        GateList poList;
        GateMap gatePool;

        GateList topologySequence;

    public:
        Network();
        ~Network();
        void parser();
        void gateWiring( std::list<char*>& );
        void printGraph();
        void resetFanOutIt();
        void topologySort();
        void evalNetwork();
        void test();
};
