#include "ScalableVectorGraphicsGenerator.hpp"
using std::endl;
ScalableVectorGraphicsGenerator::ScalableVectorGraphicsGenerator()
    : gateSize(50)
    , canvasWidth(1000)
    , canvasHeight(1000)
{
    out << "<svg "
        << "width=\"" << canvasWidth << "px\" "
        << "height=\"" << canvasHeight << "px\">" << endl;
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
    out << "</svg>" << endl;
}

void ScalableVectorGraphicsGenerator::SVGFilePrototype()
{
    Vec3 temp1 = {0, 0, 255}, temp2 = {0, 0, 0};
    drawOR(0, 0);
    drawAND(0, 100);
    drawINV(0, 200);
}

void ScalableVectorGraphicsGenerator::drawRectangle(int x, int y, int width, int height, Vec3 fillRGB, int strokeWidth, Vec3 strokeRGB)
{
    out << "\t<rect "
        << "x=\"" << x << "\" "
        << "y=\"" << y << "\" "
        << "width=\"" << width << "\" "
        << "height=\"" << height << "\" ";
    out << "style=\""
        << "fill:rgb(" << fillRGB[0] << "," << fillRGB[1] << "," << fillRGB[2] << ");"
        << "stroke-width:" << strokeWidth << ";"
        << "stroke:rgb(" << strokeRGB[0] << "," << strokeRGB[1] << "," << strokeRGB[2] << ");"
        << "\"";
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
        << x + gateSize << " " << y + gateSize / 2 << " "
        << x << " " << y + gateSize << " "
        << "Z "
        << "\" fill=\"green\" />";
    out << endl;
}
