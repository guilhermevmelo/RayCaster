#include "Ray.h"

Ray::Ray() {

}

Ray::Ray(Point origin, Point direction):origin(origin), direction(direction) {}

Vector Ray::getVector() {
    return direction - origin;
}

Vector Ray::getNormalizedVector() {
    return getVector().normalize();
}
