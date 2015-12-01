#include "Camera.h"

Camera::~Camera() { }

Camera::Camera(Point &origin, Point &lookAt, Point &up) : origin(origin), lookAt(lookAt), up(up) {
//    k = (origin - lookAt).normalize();
//    i = ((up - origin) | k).normalize();
//    j = k | i;
}

Ray* Camera::createRay(Vector &direction) {
    return new Ray(origin, direction);
}
