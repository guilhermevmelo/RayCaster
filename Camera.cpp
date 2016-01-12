#include "Camera.h"

Camera::~Camera() { }

Camera::Camera(Point &origin, Point &lookAt, Point &up) : origin(origin), lookAt(lookAt), up(up) {

    k = (origin - lookAt).normalize();
    i = ((up - origin) | k).normalize();
    j = k | i;
}

Ray Camera::createRay(const Point &direction) {
    //std::cout << "DEBUG: the ray was created" << std::endl;
    return Ray(origin, direction);
}
