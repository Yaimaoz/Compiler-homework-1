#include "Network.hpp"
#include "ScalableVectorGraphicsGenerator.hpp"
#include <fstream>
#include <iostream>
#include <string>
using std::cout;
std::string filename;
std::ofstream out;

int main(int argc, char* argv[])
{
    std::string buf1 = argv[1], buf2;
    for (auto it = buf1.rbegin(); it != buf1.rend(); ++it) {
        if (*it == '/')
            break;
        buf2 += *it;
    }
    filename.assign(buf2.rbegin(), buf2.rend());

    Network network;
    network.parser(buf1);
    network.topologySort();
    network.test();
    network.breadthFirstSearch();
    network.printLevel();
    out.open(filename + ".html", std::ios::out);

    ScalableVectorGraphicsGenerator test;
    test.SVGDeclare(1000, 1000);
    test.setGateSize(50);
    int spacing = 50;
    int x = 0, y = 0;
    for (auto level : network.levelTable) {
        y = 0;
        for (auto g : level.second) {
            switch (g->type) {
            case INPUT:
                test.drawIOBox(x, y, 0);
                break;
            case OUTPUT:
                test.drawIOBox(x, y, 1);
                break;
            case NOT:
                test.drawINV(x, y);
                break;
            case AND:
                test.drawAND(x, y);
                break;
            case OR:
                test.drawOR(x, y);
                break;
            case NAND:
                test.drawNAND(x, y);
                break;
            case NOR:
                test.drawNOR(x, y);
                break;
            case XOR:
                test.drawXOR(x, y);
                break;
            case NXOR:
                test.drawXNOR(x, y);
                break;
            }
            y += spacing * 2;
        }
        x += spacing * 2;
    }

    test.SVGEnd();
    out.close();

    return 0;
}
