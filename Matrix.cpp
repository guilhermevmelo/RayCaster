#include "Matrix.h"

Matrix::~Matrix() { }

Matrix::Matrix() { }

Matrix Matrix::world_camera(Camera &camera) {
    Matrix matriz;
    matriz(0, 0) = camera.i(0);
    matriz(0, 1) = camera.i(1);
    matriz(0, 2) = camera.i(2);
    matriz(0, 3) = -1 * (camera.i * camera.origin);

    matriz(1, 0) = camera.j(0);
    matriz(1, 1) = camera.j(1);
    matriz(1, 2) = camera.j(2);
    matriz(1, 3) = -1 * (camera.j * camera.origin);

    matriz(2, 0) = camera.k(0);
    matriz(2, 1) = camera.k(1);
    matriz(2, 2) = camera.k(2);
    matriz(2, 3) = -1 * (camera.k * camera.origin);

    matriz(3, 0) = 0.0;
    matriz(3, 1) = 0.0;
    matriz(3, 2) = 0.0;
    matriz(3, 3) = 1.0;

    return matriz;
}

Matrix Matrix::camera_world(Camera &camera) {
    Matrix matriz;
    matriz(0, 0) = camera.i(0);
    matriz(1, 0) = camera.i(1);
    matriz(2, 0) = camera.i(2);
    matriz(3, 0) = 0.0;

    matriz(0, 1) = camera.j(0);
    matriz(1, 1) = camera.j(1);
    matriz(2, 1) = camera.j(2);
    matriz(3, 1) = 0.0;

    matriz(0, 2) = camera.k(0);
    matriz(1, 2) = camera.k(1);
    matriz(2, 2) = camera.k(2);
    matriz(3, 2) = 0.0;

    matriz(0, 3) = camera.origin(0);
    matriz(1, 3) = camera.origin(1);
    matriz(2, 3) = camera.origin(2);
    matriz(3, 3) = 1.0;
    return matriz;
}

Vector operator*(const Matrix &left, const Vector &right) {
    Vector result;

    result(0) = left(0, 0) * right(0) + left(0, 1) * right(1) + left(0, 2) * right(2) + left(0, 3) * right(3);
    result(1) = left(1, 0) * right(0) + left(1, 1) * right(1) + left(1, 2) * right(2) + left(1, 3) * right(3);
    result(2) = left(2, 0) * right(0) + left(2, 1) * right(1) + left(2, 2) * right(2) + left(2, 3) * right(3);
    result(3) = left(3, 0) * right(0) + left(3, 1) * right(1) + left(3, 2) * right(2) + left(3, 3) * right(3);

    return result;
}

Point operator*(const Matrix &left, const Point &right) {
    Point result;

    result(0) = left(0, 0) * right(0) + left(0, 1) * right(1) + left(0, 2) * right(2) + left(0, 3) * right(3);
    result(1) = left(1, 0) * right(0) + left(1, 1) * right(1) + left(1, 2) * right(2) + left(1, 3) * right(3);
    result(2) = left(2, 0) * right(0) + left(2, 1) * right(1) + left(2, 2) * right(2) + left(2, 3) * right(3);
    result(3) = left(3, 0) * right(0) + left(3, 1) * right(1) + left(3, 2) * right(2) + left(3, 3) * right(3);

    return result;
}
