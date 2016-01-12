#include "Cube.h"

Cube::Cube(Point corner, double width, double height, double depth, Material &material) {
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
    Triangle t3 = Triangle(p2, p3, p4);
    Triangle t4 = Triangle(p2, p3, p4);
    Triangle t5 = Triangle(p2, p3, p4);
    Triangle t6 = Triangle(p2, p3, p4);
    Triangle t7 = Triangle(p2, p3, p4);
    Triangle t8 = Triangle(p2, p3, p4);
    Triangle t9 = Triangle(p2, p3, p4);
    Triangle t10 = Triangle(p2, p3, p4);
    Triangle t11 = Triangle(p2, p3, p4);
    Triangle t12 = Triangle(p2, p3, p4);
}

