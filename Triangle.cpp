#include "Triangle.h"
#include <limits>
#include <math.h>
#include <cstdlib>

Triangle::Triangle(Point &a, Point &b, Point &c) {
    points[0] = a;
    points[1] = b;
    points[2] = c;

    normal = (b - a) | (c - a);
    normal = normal.normalize();

    //std::cout <<  "DEBUG: Triangle::Triangle(); " << std::endl << "normal = " << normal << std::endl;
}

Hit Triangle::get_intersection(Ray &ray) {

    // Verifica se o raio e o plano sao paralelos
    if (fabs(ray.vector * normal) < 0.0000001)
        return Hit(std::numeric_limits<double>::max(), NULL);

    double d = normal * points[0];


    // tinha um - aqui
    double t = (normal * ray.origin + d) / (ray.vector * normal);

    // se t < 0 o  triangulo está atrás
    if(t < 0) {
        return Hit(std::numeric_limits<double>::max(), NULL);
    }

    Point p = ray.origin + t * ray.vector.normalize();
    //std::cout << ray.vector << " :: " << p <<  std::endl;

    Vector edge1 = points[1] - points[0];
    Vector vp1 = p - points[0];

    Vector C1 = edge1 | vp1;

    if(normal * C1 < 0) {
        return Hit(std::numeric_limits<double>::max(), NULL);
    }

    Vector edge2 = points[2] - points[1];
    Vector vp2 = p - points[1];

    Vector C2 = edge2 | vp2;

    if(normal * C2 < 0) {
        return Hit(std::numeric_limits<double>::max(), NULL);
    }

    Vector edge3 = points[0] - points[2];
    Vector vp3 = p - points[2];

    Vector C3 = edge3 | vp3;

    if(normal * C3 < 0) {
        return Hit(std::numeric_limits<double>::max(), NULL);
    }

    //std::cout << "------IT DOES!    t = " << t << std::endl;
    //std::cout << "::TOUCH!" << std::endl;
    Hit hit = Hit(t, this);
    return hit;
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

    std::cout << "Antes: " << points[0] << " " << points[1] << " " << points[2] << std::endl;
    points[0] = matrix * points[0];
    points[1] = matrix * points[1];
    points[2] = matrix * points[2];

    std::cout<< "Depois: " << points[0] << " " << points[1] << " " << points[2] << std::endl;

    std::cout << "#####" << std::endl;
}
//    if SameSide(p,a, b,c) and SameSide(p,b, a,c)
//        and SameSide(p,c, a,b) then return true
//    else return false

