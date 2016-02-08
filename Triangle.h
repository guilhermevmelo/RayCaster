#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Point.h"
#include "Ray.h"
#include "Hit.h"
#include "Vector.h"
#include "Matrix.h"

class Hit;
class Triangle {
public:
    Point points[3];
    Vector normal;

    Triangle(Point &a, Point &b, Point &c);
    Hit get_intersection(Ray &ray);
    Vector get_normal();
    double get_plane_distance();
    bool is_same_side(Point &p1, Point &p2, Point &a, Point &b);
    bool is_inside(Point &p);
    void applyTransformation(Matrix &matrix);
};

#endif // TRIANGLE_H
