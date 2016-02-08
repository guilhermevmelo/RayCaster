#ifndef ____Material__
#define ____Material__

#include "Color.h"

class Material {

public:
    Color ambient, diffuse, specular;
    double shininess;

    Material();
    Material(Color ambient, Color diffuse, Color specular, double shininess);
};

#endif /* defined(____Material__) */
