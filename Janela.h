#ifndef ____Janela__
#define ____Janela__

#include "Vetor.h"

class Janela {

public:
    double larguraImagem, alturaImagem, larguraFrame, alturaFrame, distancia;

    Janela(double larguraImagem, double alturaImagem, double larguraFrame, double alturaFrame, double distancia);
    ~Janela();

    Vetor calculeXYZ(double i, double j);
};

#endif /* defined(____Janela__) */
