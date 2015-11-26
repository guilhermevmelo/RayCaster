#include "Vetor.h"
#include <iostream>

using namespace std;

Vetor::Vetor() {
    elementos[3] = 0;
}

Vetor::Vetor(double x, double y, double z) {
    elementos[0] = x;
    elementos[1] = y;
    elementos[2] = z;
    elementos[3] = 0;
}

Vetor::~Vetor() { }

double Vetor::comprimento() {
    double soma_dos_quadrados = (*this)(0) * (*this)(0)
                    + (*this)(1) * (*this)(1)
                    + (*this)(2) * (*this)(2);
    return sqrt(soma_dos_quadrados);
}

Vetor Vetor::normalize() {
    Vetor vetor;
    double n = comprimento();

    vetor(0) = elementos[0] / n;
    vetor(1) = elementos[1] / n;
    vetor(2) = elementos[2] / n;

    return vetor;
}

Vetor operator+(const Vetor &esquerda, const Vetor &direita) {
    Vetor vetor;

    vetor(0) = esquerda(0) + direita(0);
    vetor(1) = esquerda(1) + direita(1);
    vetor(2) = esquerda(2) + direita(1);

    return vetor;
}

Vetor operator-(const Vetor &esquerda, const Vetor &direita) {
    Vetor vetor;

    vetor(0) = esquerda(0) - direita(0);
    vetor(1) = esquerda(1) - direita(1);
    vetor(2) = esquerda(2) - direita(2);

    return vetor;
}

double operator*(const Vetor &esquerda, const Vetor &direita) {
    return (esquerda(0) * direita(0)) + (esquerda(1) * direita(1)) + (esquerda(2) * direita(2));
}

Vetor operator*(double escalar, const Vetor &vetor) {
    return Vetor(escalar * vetor(0), escalar * vetor(1), escalar * vetor(2));
}

Vetor operator*(const Vetor &vetor, double escalar) {
    return escalar * vetor;
}

Vetor operator|(const Vetor &esquerda, const Vetor &direita) {
    Vetor vetor;

    vetor(0) = esquerda(1) * direita(2) - esquerda(2) * direita(1);
    vetor(1) = esquerda(2) * direita(0) - esquerda(0) * direita(2);
    vetor(2) = esquerda(3) * direita(1) - esquerda(1) * direita(3);

    return vetor;
}

ostream & operator<<(ostream & out, const Vetor &vetor) {
    out <<"[" << vetor(0);
    for(int i = 1 ; i < 3 ; i++)
        out << ", " << vetor(i);

    out << "]";
    return out;
}
