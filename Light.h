#ifndef LIGHT_H
#define LIGHT_H

#include "Point.h"

class Light {
public:
    Point position;
    Color color;
    Light();
    Light(Point position, Color color);
};

#endif // LIGHT_H
