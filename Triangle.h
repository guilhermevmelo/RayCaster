#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <vector>
#include "Point.h"
#include "Ray.h"
#include "Hit.h"

class Triangle {
public:
    Point points[3];

    Triangle(Point &a, Point &b, Point &c);
    double get_intersection(Ray &ray);
};

#endif // TRIANGLE_H
