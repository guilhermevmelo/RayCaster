#ifndef ____Camera__
#define ____Camera__

#include "Vetor.h"

class Camera {

public:
    Vetor i, j, k, origem, lookAt, up;

    Camera(Vetor &origem, Vetor &lookAt, Vetor &up);
    ~Camera();
};

#endif /* defined(____Camera__) */
