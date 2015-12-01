#ifndef ____Camera__
#define ____Camera__

#include "Vector.h"
#include "Point.h"

class Camera {

public:
    Vector i, j, k, up;
    Point origem, lookAt;

    Camera(Point &origem, Point &lookAt, Vector &up);
    ~Camera();


};

#endif /* defined(____Camera__) */
