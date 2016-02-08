#ifndef ____Matriz__
#define ____Matriz__

#include "Vector.h"
#include "Camera.h"
#include "Point.h"

class Matrix {

public:

    Matrix();
    ~Matrix();

    static Matrix world_camera(Camera &camera);
    static Matrix camera_world(Camera &camera);

    inline double& operator()(int line, int column) {
      return elements[line][column];
    };

    inline double operator()(int line, int column) const {
      return elements[line][column];
    };

    double det();

private:
    double elements[4][4];
};

Vector operator*(const Matrix &left, const Vector &right);
Point operator*(const Matrix &left, const Point &right);
std::ostream& operator<<(std::ostream& out, const Matrix &matrix);

#endif /* defined(____Matriz__) */
