#include "Triangle.h"
#include <limits>
#include <cstdlib>

Triangle::Triangle(Point &a, Point &b, Point &c) {
    points[0] = a;
    points[1] = b;
    points[2] = c;

    normal = (c - a) | (b - a);
    normal = normal;
    normal = normal.normalize();

    //std::cout <<  "DEBUG: Triangle::Triangle(); " << std::endl << "normal = " << normal << std::endl;
}

Hit Triangle::get_intersection(Ray &ray) {
    //std::cout << "::DEBUG: Triangle::get_intersection(); " << std::endl;
    //std::cout << "  (" << ray.origin * normal << " + " << get_plane_distance() << ") / ((" << ray.getVector() << ") * " << normal << ")" << std::endl;

    if (ray.getVector() * normal == 0)
        return Hit(-100, this);

    double t = - ((ray.origin * normal) + get_plane_distance())/(ray.getVector()* normal);
    //std::cout << "  t = " << t << std::endl;
    //std::cout << "  We found the intersection with the plane, now let's see if it touches the face." << std::endl;

    Point p = ray.origin + t * ray.getNormalizedVector();
    //std::cout << ray.getVector() << " :: " << p <<  std::endl;

    if (is_inside(p)) {
        //std::cout << "------IT DOES!    t = " << t << std::endl;
        Hit hit = Hit(t, this);
        return hit;
    }
    //std::cout << "------IT DOES NOT!    t = MAX" << std::endl;
    return Hit(-100, this);

}

Vector Triangle::get_normal() {
    return normal;
}

double Triangle::get_plane_distance() {
    Vector normal_base = normal - normal.length();
    return (normal_base - Vector(0,0,0)).length();
}

bool Triangle::is_same_side(Point &p1, Point &p2, Point &a, Point &b) {
    Vector v1 = (b - a) | (p1 - a);
    Vector v2 = (b - a) | (p2 - a);

    if (v1 * v2 >= 0)
        return true;
    return false;
}

//function SameSide(p1,p2, a,b)
//    cp1 = CrossProduct(b-a, p1-a)
//    cp2 = CrossProduct(b-a, p2-a)
//    if DotProduct(cp1, cp2) >= 0 then return true
//    else return false

bool Triangle::is_inside(Point &p) {
    if (is_same_side(p, points[0], points[1], points[2]) &&
        is_same_side(p, points[1], points[0], points[2]) &&
        is_same_side(p, points[2], points[0], points[1]))
        return true;
    return false;
}

void Triangle::applyTransformation(Matrix &matrix) {
    points[0] = matrix * points[0];
    points[1] = matrix * points[1];
    points[2] = matrix * points[2];

    std::cout << points[0] << std::endl;
    std::cout << points[1] << std::endl;
    std::cout << points[2] << std::endl;
    std::cout << "#####" << std::endl;
}
//    if SameSide(p,a, b,c) and SameSide(p,b, a,c)
//        and SameSide(p,c, a,b) then return true
//    else return false

