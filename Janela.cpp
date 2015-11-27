#include "Janela.h"

Janela::~Janela() { }

Janela::Janela(double larguraImagem, double alturaImagem, double larguraFrame, double alturaFrame, double distancia)
  : larguraImagem(larguraImagem), alturaImagem(alturaImagem), larguraFrame(larguraFrame), alturaFrame(alturaFrame), distancia(distancia) {}

Vector Janela::calculeXYZ(double i, double j) {
    double deltaX = larguraImagem / larguraFrame;
    double deltaY = alturaImagem / alturaFrame;

    double x = -(larguraImagem/2) + (deltaX/2) + (deltaX * j);
    double y = ((alturaImagem/2) - (deltaY/2)) - (deltaY * i);
    double z = -distancia;
    Vector vetor(x, y, z);

    return vetor;
}
