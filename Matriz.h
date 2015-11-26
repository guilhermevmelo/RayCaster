#ifndef ____Matriz__
#define ____Matriz__

#include "Vetor.h"
#include "Camera.h"

class Matriz {

public:

    Matriz();
    ~Matriz();

    Matriz mundo_camera(Camera &camera);
    Matriz camera_mundo(Camera &camera);

    inline double& operator()(int linha, int coluna) {
      return elementos[linha][coluna];
    };

    inline double operator()(int linha, int coluna) const {
      return elementos[linha][coluna];
    };

private:
    double elementos[4][4];
};

#endif /* defined(____Matriz__) */
