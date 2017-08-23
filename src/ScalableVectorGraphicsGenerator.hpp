#pragma once
#include <fstream>

enum Type { WIRE, BUFFER, AND, OR, NOT, NAND, NOR, XOR, NXOR };
class ScalableVectorGraphicsGenerator {

public:
  ScalableVectorGraphicsGenerator();
  ~ScalableVectorGraphicsGenerator();
  void SVGFilePrototype();

private:
  Type type;
};
