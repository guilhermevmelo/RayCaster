#include "Triangle.h"

Triangle::Triangle(Point &a, Point &b, Point &c) {
    points[0] = a;
    points[1] = b;
    points[2] = c;

    normal = (c - a) | (b - a);
    normal = normal.normalize();
}

double Triangle::get_intersection(Ray &ray) {
    double t = - (ray.origin * normal + d)/(ray.direction * normal);
}

Vector Triangle::get_normal() {
    return normal;
}

double Triangle::get_plane_distance() {
    Vector normal_base = normal - normal.length();
    return (normal_base - Vector(0,0,0)).length();
}
