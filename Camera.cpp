#include "Camera.h"

Camera::~Camera() { }

Camera::Camera(Point &origin, Point &lookAt, Point &up) : origin(origin), lookAt(lookAt), up(up) {
    k = (origin - lookAt).normalize();
    i = ((up - origin) | k).normalize();
    j = k | i;

    std::cout << "DEBUG: i: " << i << " j: " << j << " k: " << k << std::endl;
}

Ray Camera::createRay(const Point &direction) {
    //std::cout << "DEBUG: the ray was created" << std::endl;
    Point camera_origin(0,0,0);
    return Ray(camera_origin, direction);
}
