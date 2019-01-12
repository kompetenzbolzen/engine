#pragma once

#include <vector>
#include <cmath>

#include "cRender.h"

#define _DEPTH 100

struct sCoord3d
{
  int x;
  int y;
  int z;

  sCoord3d operator+(sCoord3d p)
  {
    sCoord3d ret;
    ret.x = x + p.x;
    ret.y = y + p.y;
    ret.z = z + p.z;
    return ret;
  }
};

struct sVector
{
  sCoord3d origin;
  sCoord3d direction;

  char c;
  WORD color;
};

class cWiremesh
{
public:

  cWiremesh();

  virtual ~cWiremesh();

  void addVector(sCoord3d _origin, sCoord3d _vector, char _char, WORD _color);

  void rotate(sCoord3d _val);

  sCoord3d getPosition();

  void setPosition(int _x, int _y, int _z);

  void setPosition(sCoord3d _pos);

  void reset();

  void write(cRender *_render);

protected:

private:

  sPos translate(sCoord3d _coord, sCoord3d _origin);

  sCoord3d position;

  std::vector<sVector> vectors;
};
