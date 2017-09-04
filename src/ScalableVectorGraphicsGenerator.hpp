#pragma once
#include <fstream>
#include <list>
#include <string>
#include <vector>
extern std::string filename;
extern std::ofstream out;
typedef unsigned int Vec3[3];
class ScalableVectorGraphicsGenerator {

public:
    ScalableVectorGraphicsGenerator();
    ScalableVectorGraphicsGenerator(int, int);
    ~ScalableVectorGraphicsGenerator();
    void SVGDeclare(int, int);
    void SVGEnd();
    void SVGFilePrototype();
    void setGateSize(int);

    void drawRectangle(int, int, int, int, Vec3, int, Vec3);
    void drawCircle(int, int, int, Vec3, int, Vec3);
    void drawAND(int, int);
    void drawOR(int, int);
    void drawINV(int, int);

private:
    int gateSize;
    int canvasWidth, canvasHeight;
};
