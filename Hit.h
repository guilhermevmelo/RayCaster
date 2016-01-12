#ifndef HIT_H
#define HIT_H

#include "Color.h"
#include "Triangle.h"

class Triangle;
class Hit {
public:
    Hit(double distance, Triangle *face);

    double distance;
    Triangle *face;

    Color getColor();
};

#endif // HIT_H
