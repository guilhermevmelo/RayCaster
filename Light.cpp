#include "Light.h"

Light::Light(){}

Light::Light(Point position, Color color):position(position),color(color){}

Color operator * (const Light &light, const Material &material) {
    Color c = light.color;

    c.r = c.r * material.ambient.r * material.diffuse.r * material.specular.r;
    c.g = c.g * material.ambient.r * material.diffuse.g * material.specular.g;
    c.b = c.b * material.ambient.r * material.diffuse.b * material.specular.b;

    return c;
}
