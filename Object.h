#ifndef OBJECT_H
#define OBJECT_H

#include "Triangle.h"
#include "Hit.h"
#include "Material.h"
#include <vector>

class Object {
public:
    std::vector<Triangle> faces;
    Material material;
    Object(Material material);

    Hit hit();
    void addTriangle(Triangle t);
};

#endif // OBJECT_H
