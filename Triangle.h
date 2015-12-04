#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Point.h"
#include "Ray.h"
#include "Vector.h"

class Triangle {
public:
    Point points[3];
    Vector normal;

    Triangle(Point &a, Point &b, Point &c);
    double get_intersection(Ray &ray);
    Vector get_normal();
    double get_plane_distance();
};

#endif // TRIANGLE_H
