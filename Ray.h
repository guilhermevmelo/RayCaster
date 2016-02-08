#ifndef RAIO_H
#define RAIO_H

#include "Vector.h"

class Ray {
public:
    Point origin;
    Point direction;
    Vector vector;

    Ray();
    Ray(Point origin, Point direction);
};

#endif // RAIO_H
