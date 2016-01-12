#ifndef LIGHT_H
#define LIGHT_H

#include "Point.h"
#include "Color.h"
#include "Material.h"

class Light {
public:
    Point position;
    Color color;
    Light();
    Light(Point position, Color color);
};


Color operator * (const Light &light, const Material &material);

#endif // LIGHT_H
