#ifndef RAIO_H
#define RAIO_H

#include "Vector.h"

class Ray {
public:
    Ray();
    Ray(Point &origin, Vector &direction);
    ~Ray();
    Vector direction;
    Point origin;
};

#endif // RAIO_H
