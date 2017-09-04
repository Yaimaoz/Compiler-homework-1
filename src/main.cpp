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
            test.drawOR(x, y);
            y += spacing * 2;
        }
        x += spacing * 2;
    }

    test.SVGEnd();
    out.close();

    return 0;
}
