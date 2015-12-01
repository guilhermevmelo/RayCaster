#include "Camera.h"

Camera::~Camera() { }

Camera::Camera(Vector &origin, Vector &lookAt, Vector &up) : origem(origin), lookAt(lookAt), up(up) {
    k = (origin - lookAt).normalize();
    i = ((up - origin) | k).normalize();
    j = k | i;
}
