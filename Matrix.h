#ifndef ____Matriz__
#define ____Matriz__

#include "Vector.h"
#include "Camera.h"

class Matrix {

public:

    Matrix();
    ~Matrix();

    Matrix world_camera(Camera &camera);
    Matrix camera_world(Camera &camera);

    inline double& operator()(int line, int column) {
      return elements[line][column];
    };

    inline double operator()(int line, int column) const {
      return elements[line][column];
    };

private:
    double elements[4][4];
};

#endif /* defined(____Matriz__) */
