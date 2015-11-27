#ifndef ____Material__
#define ____Material__

#include "Color.h"

class Material {

public:
    Cor ambiente, difusa, especular;

    Material(Cor ambiente, Cor difusa, Cor especular);
    ~Material();
};

#endif /* defined(____Material__) */
