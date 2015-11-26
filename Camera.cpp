#include "Camera.h"

Camera::~Camera() { }

Camera::Camera(Vetor &origem, Vetor &lookAt, Vetor &up) : origem(origem), lookAt(lookAt), up(up) {
    k = (origem - lookAt).normalize();
    i = ((up - origem) | k).normalize();
    j = k | i;
}
