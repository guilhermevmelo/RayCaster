#include "Camera.h"

Camera::~Camera() { }

Camera::Camera(Point &origin, Point &lookAt, Point &up) : origem(origin), lookAt(lookAt), up(up) {
    k = (origin - lookAt).normalize();
    i = ((up - origin) | k).normalize();
    j = k | i;
}
