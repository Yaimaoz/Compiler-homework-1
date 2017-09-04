#pragma once
#include<string>
#include<cstring>
#include<list>
#include<iostream>
class Gate;
typedef std::list<Gate*> GateList;

enum GateType{ NONE, BUFFER, AND, OR, NOT, NAND, NOR, XOR, NXOR, INPUT, OUTPUT };
class Gate{

    public:
        Gate();
        void eval();

        
        std::string name;
        GateList fanins;
        GateList fanouts;
        int value;
        GateType type;
        bool isTrav;

        GateList::iterator fanOutIt;
};

