#include "Camera.h"

Camera::~Camera() { }

Camera::Camera(Vector &origem, Vector &lookAt, Vector &up) : origem(origem), lookAt(lookAt), up(up) {
    k = (origem - lookAt).normalize();
    i = ((up - origem) | k).normalize();
    j = k | i;
}
