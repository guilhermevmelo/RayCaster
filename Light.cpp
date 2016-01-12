#include "Light.h"

Light::Light(){}

Light::Light(Point position, Color color):position(position),color(color){}

Color operator * (const Light &light, const Material &material) {
    Color c = light.color;

    c.r = c.r * material.ambient * material.diffuse * material.specular;
    c.g = c.g * material.ambient * material.diffuse * material.specular;
    c.b = c.b * material.ambient * material.diffuse * material.specular;

    return c;
}
