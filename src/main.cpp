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

    out.open(filename + ".html", std::ios::out);
    ScalableVectorGraphicsGenerator test;

    test.SVGFilePrototype();
    out.close();
    return 0;
}
