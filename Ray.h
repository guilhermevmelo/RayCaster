#ifndef RAIO_H
#define RAIO_H

#include "Vector.h"

class Ray {
public:
    Point origin;
    Point direction;

    Ray();
    Ray(Point origin, Point direction);
    ~Ray();
};

#endif // RAIO_H
