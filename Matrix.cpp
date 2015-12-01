#include "Matrix.h"

Matrix::~Matrix() { }

Matrix::Matrix() { }

Matrix Matrix::world_camera(Camera &camera) {
    Matrix matriz;
    matriz(0, 0) = camera.i(0);
    matriz(0, 1) = camera.i(1);
    matriz(0, 2) = camera.i(2);
    matriz(0, 3) = -1 * (camera.i * camera.origem);

    matriz(1, 0) = camera.j(0);
    matriz(1, 1) = camera.j(1);
    matriz(1, 2) = camera.j(2);
    matriz(1, 3) = -1 * (camera.j * camera.origem);

    matriz(2, 0) = camera.k(0);
    matriz(2, 1) = camera.k(1);
    matriz(2, 2) = camera.k(2);
    matriz(2, 3) = -1 * (camera.k * camera.origem);

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

    matriz(0, 3) = camera.origem(1);
    matriz(1, 3) = camera.origem(2);
    matriz(2, 3) = camera.origem(3);
    matriz(3, 3) = 1.0;
    return matriz;
}
