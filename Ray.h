#ifndef RAIO_H
#define RAIO_H

#include "Vector.h"

class Ray {
public:
    Point origin;
    Point direction;

    Ray();
    Ray(Point origin, Point direction);

    Vector getVector();
    Vector getNormalizedVector();
};

#endif // RAIO_H
