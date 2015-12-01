#include "Point.h"

#include <iostream>

using namespace std;

Point::Point() {
    elements[3] = 0;
}

Point::Point(double x, double y, double z) {
    elements[0] = x;
    elements[1] = y;
    elements[2] = z;
    elements[3] = 0;
}

Point::~Point() { }

