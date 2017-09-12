#include "ScalableVectorGraphicsGenerator.hpp"
using std::endl;
ScalableVectorGraphicsGenerator::ScalableVectorGraphicsGenerator()
    : gateSize(50)
    , canvasWidth(1000)
    , canvasHeight(1000)
{
}

ScalableVectorGraphicsGenerator::~ScalableVectorGraphicsGenerator()
{
}

void ScalableVectorGraphicsGenerator::drawRectangle(int x, int y, int width, int height, std::string color)
{
    out << "\t<rect "
        << "x=\"" << x << "\" "
        << "y=\"" << y << "\" "
        << "width=\"" << width << "\" "
        << "height=\"" << height << "\" ";
    out << "fill=\""
        << color
        << "\" ";
    out << " />" << endl;
}

void ScalableVectorGraphicsGenerator::drawAND(int x, int y)
{
    out << "\t<path d=";
    out << "\"M "
        << x << " " << y << " "
        << x + gateSize << " " << y << " "
        << "Q "
        << x + gateSize * 1.5 << " " << y + gateSize / 2 << " "
        << x + gateSize << " " << y + gateSize << " "
        << "L "
        << x << " " << y + gateSize << " "
        << "Z "
        << "\" fill=\"red\" />";
    out << endl;
}

void ScalableVectorGraphicsGenerator::drawOR(int x, int y)
{
    out << "\t<path d=";
    out << "\"M "
        << x << " " << y << " "
        << x + gateSize << " " << y << " "
        << "Q "
        << x + gateSize * 1.5 << " " << y + gateSize / 2 << " "
        << x + gateSize << " " << y + gateSize << " "
        << "L "
        << x << " " << y + gateSize << " "
        << "Q "
        << x + gateSize / 2 << " " << y + gateSize / 2 << " "
        << x << " " << y << " "
        << "\" fill=\"yellow\" />";
    out << endl;
}

void ScalableVectorGraphicsGenerator::drawINV(int x, int y)
{
    out << "\t<path d=";
    out << "\"M "
        << x << " " << y << " "
        << "L "
        << x + gateSize + gateSize / 4 << " " << y + gateSize / 2 << " "
        << x << " " << y + gateSize << " "
        << "Z "
        << "\" fill=\"green\" />";
    out << endl;

    out << "\t<circle ";
    out << "cx=" << x + gateSize + gateSize / 4 << " "
        << "cy=" << y + gateSize / 2 << " "
        << "r=" << gateSize / 7 << " "
        << "fill=\"green\" />";
    out << endl;
}

void ScalableVectorGraphicsGenerator::drawNAND(int x, int y)
{
    out << "\t<path d=";
    out << "\"M "
        << x << " " << y << " "
        << x + gateSize << " " << y << " "
        << "Q "
        << x + gateSize * 1.5 << " " << y + gateSize / 2 << " "
        << x + gateSize << " " << y + gateSize << " "
        << "L "
        << x << " " << y + gateSize << " "
        << "Z "
        << "\" fill=\"red\" />";
    out << endl;

    out << "\t<circle ";
    out << "cx=" << x + gateSize + gateSize / 3 << " "
        << "cy=" << y + gateSize / 2 << " "
        << "r=" << gateSize / 7 << " "
        << "fill=\"red\" />";
    out << endl;
}

void ScalableVectorGraphicsGenerator::drawNOR(int x, int y)
{
    out << "\t<path d=";
    out << "\"M "
        << x << " " << y << " "
        << x + gateSize << " " << y << " "
        << "Q "
        << x + gateSize * 1.5 << " " << y + gateSize / 2 << " "
        << x + gateSize << " " << y + gateSize << " "
        << "L "
        << x << " " << y + gateSize << " "
        << "Q "
        << x + gateSize / 2 << " " << y + gateSize / 2 << " "
        << x << " " << y << " "
        << "\" fill=\"yellow\" />";
    out << endl;

    out << "\t<circle ";
    out << "cx=" << x + gateSize + gateSize / 3 << " "
        << "cy=" << y + gateSize / 2 << " "
        << "r=" << gateSize / 7 << " "
        << "fill=\"yellow\" />";
    out << endl;
}

void ScalableVectorGraphicsGenerator::drawXNOR(int x, int y)
{
    out << "\t<path d=";
    out << "\"M "
        << x + gateSize / 4 << " " << y << " "
        << x + gateSize << " " << y << " "
        << "Q "
        << x + gateSize * 1.5 << " " << y + gateSize / 2 << " "
        << x + gateSize << " " << y + gateSize << " "
        << "L "
        << x + gateSize / 4 << " " << y + gateSize << " "
        << "Q "
        << x + gateSize / 2 + gateSize / 4 << " " << y + gateSize / 2 << " "
        << x + gateSize / 4 << " " << y << " "
        << "\" fill=\"blue\" />";
    out << endl;

    out << "\t<path d=";
    out << "\"M "
        << x << " " << y << " "
        << x + gateSize / 8 << " " << y << " "
        << "Q "
        << x + gateSize / 2 << " " << y + gateSize / 2 << " "
        << x + gateSize / 8 << " " << y + gateSize << " "
        << "L "
        << x << " " << y + gateSize << " "
        << "Q "
        << x + gateSize / 2 << " " << y + gateSize / 2 << " "
        << x << " " << y << " "
        << "\" fill=\"blue\" />";
    out << endl;

    out << "\t<circle ";
    out << "cx=" << x + gateSize + gateSize / 3 << " "
        << "cy=" << y + gateSize / 2 << " "
        << "r=" << gateSize / 7 << " "
        << "fill=\"blue\" />";
    out << endl;
}

void ScalableVectorGraphicsGenerator::drawXOR(int x, int y)
{
    out << "\t<path d=";
    out << "\"M "
        << x + gateSize / 4 << " " << y << " "
        << x + gateSize << " " << y << " "
        << "Q "
        << x + gateSize * 1.5 << " " << y + gateSize / 2 << " "
        << x + gateSize << " " << y + gateSize << " "
        << "L "
        << x + gateSize / 4 << " " << y + gateSize << " "
        << "Q "
        << x + gateSize / 2 + gateSize / 4 << " " << y + gateSize / 2 << " "
        << x + gateSize / 4 << " " << y << " "
        << "\" fill=\"pink\" />";
    out << endl;

    out << "\t<path d=";
    out << "\"M "
        << x << " " << y << " "
        << x + gateSize / 8 << " " << y << " "
        << "Q "
        << x + gateSize / 2 << " " << y + gateSize / 2 << " "
        << x + gateSize / 8 << " " << y + gateSize << " "
        << "L "
        << x << " " << y + gateSize << " "
        << "Q "
        << x + gateSize / 2 << " " << y + gateSize / 2 << " "
        << x << " " << y << " "
        << "\" fill=\"pink\" />";
    out << endl;
}

void ScalableVectorGraphicsGenerator::drawIOBox(int x, int y, int flag)
{
    if (flag == 0) {
        drawRectangle(x, y + gateSize / 4, gateSize, gateSize / 2, "Cyan");
    }
    else if ( flag == 1 ){
        drawRectangle(x, y + gateSize / 4, gateSize, gateSize / 2, "Fuchsia");
    } else {
        drawRectangle(x, y + gateSize / 4, gateSize, gateSize / 2, "gray");
    }
}

void ScalableVectorGraphicsGenerator::drawPath(std::vector< int >& path)
{
    out << "\t<path d=";
    out << "\"M " << path[0] << " " << path[1] << " ";
    out << "L ";
    for (int i = 2; i < path.size(); ++i)
        out << path[i] << " ";
    out << "\" stroke=\"black\" />";
    out << endl;
}

void ScalableVectorGraphicsGenerator::drawText(int x, int y, std::string& text)
{
    out << "\t<text "
        << "x=\"" << x + gateSize / 2 << "\" "
        << "y=\"" << y + gateSize / 2 << "\" >"
        << text << "</text>";
    out << endl;
}

void ScalableVectorGraphicsGenerator::SVGBegin(std::string filename, int width, int height)
{
    out.open(filename+".html", std::ios::out);
    out << "<svg "
        << "width=\"" << width << "px\" "
        << "height=\"" << height << "px\">" << endl;
    canvasWidth = width;
    canvasHeight = height;
}

void ScalableVectorGraphicsGenerator::SVGEnd()
{
    out << "</svg>" << endl;
    out.close();
}

void ScalableVectorGraphicsGenerator::setGateSize(int inSize)
{
    gateSize = inSize;
}

int ScalableVectorGraphicsGenerator::getGateSize()
{
    return gateSize;
}
