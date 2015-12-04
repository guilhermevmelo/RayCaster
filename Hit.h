#ifndef HIT_H
#define HIT_H

#include "Color.h"
#include "Triangle.h"
#include "Material.h"

class Hit {
public:
    Hit(double distance, Triangle face, Material material);

    double t;
    Triangle face;
    Material material;

    Color getColor();
};

#endif // HIT_H
