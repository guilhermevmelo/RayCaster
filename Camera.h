#ifndef ____Camera__
#define ____Camera__

#include "Vector.h"
#include "Point.h"

class Camera {

public:
    Vector i, j, k;
    Point origem, lookAt, up;

    Camera(Point &origem, Point &lookAt, Point &up);
    ~Camera();


};

#endif /* defined(____Camera__) */
