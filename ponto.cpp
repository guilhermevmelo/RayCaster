#include "ponto.h"

#include <iostream>

using namespace std;

Ponto::Ponto() {
    elementos[3] = 0;
}

Ponto::Ponto(double x, double y, double z) {
    elementos[0] = x;
    elementos[1] = y;
    elementos[2] = z;
    elementos[3] = 0;
}

Ponto::~Ponto() { }

