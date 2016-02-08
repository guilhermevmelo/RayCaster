#include "Window.h"

Window::~Window() { }

Window::Window(double imageWidth, double imageHeight, double frameWidth, double frameHeight, double distance)
  : imageWidth(imageWidth), imageHeight(imageHeight), frameWidth(frameWidth), frameHeight(frameHeight), distance(distance) {}

Point Window::calculateXYZ(double i, double j) {
    double deltaX = imageWidth / frameWidth;
    double deltaY = imageHeight / frameHeight;

    double x = -(imageWidth/2.0) + (deltaX/2.0) + (deltaX * j);
    double y = ((imageHeight/2.0) - (deltaY/2.0)) - (deltaY * i);
    double z = -distance;
    Point point(x, y, z);

    //std::cout << "pixel coordinates: x = " << x << " y =" << y << " z =" << z << std::endl;

    return point;
}
