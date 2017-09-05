#include "ScalableVectorGraphicsGenerator.hpp"
using std::endl;
ScalableVectorGraphicsGenerator::ScalableVectorGraphicsGenerator()
    : gateSize(50)
    , canvasWidth(1000)
    , canvasHeight(1000)
{
}

ScalableVectorGraphicsGenerator::ScalableVectorGraphicsGenerator(int width, int height)
    : gateSize(50)
    , canvasWidth(width)
    , canvasHeight(height)
{
    out << "<svg "
        << "width=\"" << canvasWidth << "px\" "
        << "height=\"" << canvasHeight << "px\">" << endl;
}

ScalableVectorGraphicsGenerator::~ScalableVectorGraphicsGenerator()
{
}

void ScalableVectorGraphicsGenerator::SVGFilePrototype()
{
    Vec3 temp1 = {0, 0, 255}, temp2 = {0, 0, 0};
    drawOR(0, 0);
    drawAND(0, 100);
    drawINV(0, 200);
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

void ScalableVectorGraphicsGenerator::drawCircle(int cx, int cy, int r, Vec3 fillRGB, int strokeWidth, Vec3 strokeRGB)
{
    out << "\t<circle "
        << "cx=\"" << cx << "\" "
        << "cy=\"" << cy << "\" "
        << "r=\"" << r << "\" ";
    out << "style=\""
        << "fill:rgb(" << fillRGB[0] << "," << fillRGB[1] << "," << fillRGB[2] << ");"
        << "stroke-width:" << strokeWidth << ";"
        << "stroke:rgb(" << strokeRGB[0] << "," << strokeRGB[1] << "," << strokeRGB[2] << ");"
        << "\"";
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
        << "\" fill=\"black\" />";
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
        << "\" fill=\"black\" />";
    out << endl;

    out << "\t<circle ";
    out << "cx=" << x + gateSize + gateSize / 3 << " "
        << "cy=" << y + gateSize / 2 << " "
        << "r=" << gateSize / 7 << " "
        << "fill=\"black\" />";
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
    if (flag) {
        drawRectangle(x, y + gateSize / 4, gateSize, gateSize / 2, "Cyan");
    }
    else {
        drawRectangle(x, y + gateSize / 4, gateSize, gateSize / 2, "Fuchsia");
    }
}

void ScalableVectorGraphicsGenerator::drawPath(std::vector< int > path)
{
    out << "\t<path d=";
    out << "\"M ";
    for (int i = 0; i < path.size(); ++i)
        out << path[i] << " ";
    out << " />";
    out << endl;
}

void ScalableVectorGraphicsGenerator::SVGDeclare(int width, int height)
{
    out << "<svg "
        << "width=\"" << width << "px\" "
        << "height=\"" << height << "px\">" << endl;
    canvasWidth = width;
    canvasHeight = height;
}

void ScalableVectorGraphicsGenerator::SVGEnd()
{
    out << "</svg>" << endl;
}

void ScalableVectorGraphicsGenerator::setGateSize(int inSize)
{
    gateSize = inSize;
}
