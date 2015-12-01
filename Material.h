#ifndef ____Material__
#define ____Material__

#include "Color.h"

class Material {

public:
    Color ambient, diffuse, specular;

    Material(Color ambient, Color diffuse, Color specular);
    ~Material();
};

#endif /* defined(____Material__) */
