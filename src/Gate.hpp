#pragma once
#include <cstring>
#include <iostream>
#include <list>
#include <string>
class Gate;
typedef std::list< Gate* > GateList;

enum GateType { NONE,
                BUFFER,
                AND,
                OR,
                NOT,
                NAND,
                NOR,
                XOR,
                NXOR,
                INPUT,
                OUTPUT };
class Gate {

public:
    Gate();
    void eval();

    std::string name;
    GateList fanins;
    GateList fanouts;
    int value;
    GateType type;
    bool isTrav;
    size_t level;

    GateList::iterator fanOutIt;
};
