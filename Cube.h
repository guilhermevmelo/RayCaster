#ifndef CUBE_H
#define CUBE_H

#include "Point.h"
#include "Material.h"
#include "Object.h"

class Cube : public Object {
public:
    Material material;
    Cube(Point corner, double width, double height, double depth, Material &material);
};

#endif // CUBE_H
