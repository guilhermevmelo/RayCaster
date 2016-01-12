#ifndef ____Janela__
#define ____Janela__

#include "Point.h"
#include <iostream>
class Window {

public:
    double imageWidth, imageHeight, frameWidth, frameHeight, distance;

    Window(double imageWidth, double imageHeight, double frameWidth, double frameHeight, double distance);
    ~Window();

    Point calculateXYZ(double i, double j);
};

#endif /* defined(____Janela__) */
