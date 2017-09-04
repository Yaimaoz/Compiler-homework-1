#include "Gate.hpp"

Gate::Gate()
    : value(-1)
    , type(NONE)
    , isTrav(false)
    , level(1000)
{
}

void Gate::eval()
{

    switch (type) {

    case BUFFER:
        value = fanins.front()->value;
        break;
    case AND:
        value = fanins.front()->value && fanins.back()->value;
        break;
    case OR:
        value = fanins.front()->value || fanins.back()->value;
        break;
    case NOT:
        value = !fanins.front()->value;
        break;
    case NAND:
        value = !(fanins.front()->value && fanins.back()->value);
        break;
    case NOR:
        value = !(fanins.front()->value || fanins.back()->value);
        break;
    case XOR:
        value = fanins.front()->value != fanins.back()->value;
        break;
    case NXOR:
        value = fanins.front()->value == fanins.back()->value;
        break;
    }
}
