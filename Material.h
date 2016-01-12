#ifndef ____Material__
#define ____Material__

#include "Color.h"

class Material {

public:
    double ambient, diffuse, specular;

    Material();
    Material(double ambient, double diffuse, double specular);
};

#endif /* defined(____Material__) */
