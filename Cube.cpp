#include "Cube.h"

Cube::Cube(Point corner, double width, double height, double depth, Material &material):material(material) {
    Point p1 = corner;
    Point p2 = Point(corner(0) + width, corner(1), corner(2));
    Point p3 = Point(corner(0) + width, corner(1), corner(2) + depth);
    Point p4 = Point(corner(0), corner(1), corner(2) + depth);
    Point p5 = Point(corner(0), corner(1) + height, corner(2) + depth);
    Point p6 = Point(corner(0), corner(1) + height, corner(2));
    Point p7 = Point(corner(0) + width, corner(1) + height, corner(2));
    Point p8 = Point(corner(0) + width, corner(1) + height, corner(2) + depth);

    Triangle t1 = Triangle(p1, p2, p4);
    Triangle t2 = Triangle(p2, p3, p4);
    Triangle t3 = Triangle(p2, p8, p3);
    Triangle t4 = Triangle(p2, p7, p8);
    Triangle t5 = Triangle(p2, p6, p7);
    Triangle t6 = Triangle(p2, p1, p6);
    Triangle t7 = Triangle(p1, p4, p6);
    Triangle t8 = Triangle(p4, p5, p6);
    Triangle t9 = Triangle(p5, p4, p8);
    Triangle t10 = Triangle(p4, p3, p8);
    Triangle t11 = Triangle(p5, p8, p6);
    Triangle t12 = Triangle(p6, p8, p7);

    addTriangle(t1);
    addTriangle(t2);
    addTriangle(t3);
    addTriangle(t4);
    addTriangle(t5);
    addTriangle(t6);
    addTriangle(t7);
    addTriangle(t8);
    addTriangle(t9);
    addTriangle(t10);
    addTriangle(t11);
    addTriangle(t12);
}

