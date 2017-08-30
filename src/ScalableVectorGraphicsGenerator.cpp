#include "ScalableVectorGraphicsGenerator.hpp"
using std::endl;
ScalableVectorGraphicsGenerator::ScalableVectorGraphicsGenerator() {}

ScalableVectorGraphicsGenerator::~ScalableVectorGraphicsGenerator() {}

void ScalableVectorGraphicsGenerator::SVGFilePrototype()
{
    Vec3 temp1 = {0, 0, 255}, temp2 = {0, 0, 0};
    out << "<svg width=\"400px\" height=\"450px\">" << endl;
    drawAND(0, 0);
    out << "</svg>" << endl;
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
        << x + 100 << " " << y << " "
        << "Q "
        << x + 150 << " " << y + 50 << " "
        << x + 100 << " " << y + 100 << " "
        << "L "
        << x << " " << y + 100 << " "
        << "Z "
        << "\" stroke=\"black\" fill=\"none\" />";
    out << endl;
}
