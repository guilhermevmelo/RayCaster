#ifndef RAIO_H
#define RAIO_H

#include "Vector.h"

class Ray {
public:
    Point origin;
    Vector direction;

    Ray();
    Ray(Point origin, Vector direction);
    ~Ray();
};

#endif // RAIO_H
