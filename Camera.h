#ifndef ____Camera__
#define ____Camera__

#include "Vector.h"
#include "Point.h"
#include "Ray.h"

class Camera {

public:
    Vector i, j, k;
    Point origin, lookAt, up;

    Camera(Point &origin, Point &lookAt, Point &up);
    ~Camera();

    Ray createRay(const Point &direction);
};

#endif /* defined(____Camera__) */
