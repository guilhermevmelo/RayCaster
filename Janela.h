#ifndef ____Janela__
#define ____Janela__

#include "Vector.h"

class Janela {

public:
    double larguraImagem, alturaImagem, larguraFrame, alturaFrame, distancia;

    Janela(double larguraImagem, double alturaImagem, double larguraFrame, double alturaFrame, double distancia);
    ~Janela();

    Vector calculeXYZ(double i, double j);
};

#endif /* defined(____Janela__) */
