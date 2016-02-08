#ifndef OBJECT_H
#define OBJECT_H

#include "Triangle.h"
#include "Hit.h"
#include "Material.h"
#include "Matrix.h"
#include <vector>

class Object {
public:
    std::vector<Triangle> faces;
    Material material;
    Object(Material material);
    Object();

    Hit hit();
    void addTriangle(Triangle t);
    void applyTransformation(Matrix &matrix);
};

#endif // OBJECT_H
