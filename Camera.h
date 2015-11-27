#ifndef ____Camera__
#define ____Camera__

#include "Vector.h"
#include "ponto.h"

class Camera {

public:
    Vector i, j, k, up;
    Ponto origem, lookAt;

    Camera(Ponto &origem, Ponto &lookAt, Vector &up);
    ~Camera();
};

#endif /* defined(____Camera__) */
