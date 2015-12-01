#include "Vector.h"
#include <iostream>

using namespace std;

Vector::Vector() {
    elements[3] = 0;
}

Vector::Vector(double x, double y, double z) {
    elements[0] = x;
    elements[1] = y;
    elements[2] = z;
    elements[3] = 0;
}

Vector::~Vector() { }

double Vector::length() {
    double soma_dos_quadrados = (*this)(0) * (*this)(0)
                    + (*this)(1) * (*this)(1)
                    + (*this)(2) * (*this)(2);
    return sqrt(soma_dos_quadrados);
}

Vector Vector::normalize() {
    Vector vetor;
    double n = length();

    vetor(0) = elements[0] / n;
    vetor(1) = elements[1] / n;
    vetor(2) = elements[2] / n;

    return vetor;
}

Vector operator+(const Vector &left, const Vector &right) {
    Vector vetor;

    vetor(0) = left(0) + right(0);
    vetor(1) = left(1) + right(1);
    vetor(2) = left(2) + right(1);

    return vetor;
}

Vector operator-(const Vector &esquerda, const Vector &direita) {
    Vector vetor;

    vetor(0) = esquerda(0) - direita(0);
    vetor(1) = esquerda(1) - direita(1);
    vetor(2) = esquerda(2) - direita(2);

    return vetor;
}

double operator*(const Vector &esquerda, const Vector &direita) {
    return (esquerda(0) * direita(0)) + (esquerda(1) * direita(1)) + (esquerda(2) * direita(2));
}

Vector operator*(double escalar, const Vector &vetor) {
    return Vector(escalar * vetor(0), escalar * vetor(1), escalar * vetor(2));
}

Vector operator*(const Vector &vetor, double escalar) {
    return escalar * vetor;
}

Vector operator|(const Vector &esquerda, const Vector &direita) {
    Vector vetor;

    vetor(0) = esquerda(1) * direita(2) - esquerda(2) * direita(1);
    vetor(1) = esquerda(2) * direita(0) - esquerda(0) * direita(2);
    vetor(2) = esquerda(3) * direita(1) - esquerda(1) * direita(3);

    return vetor;
}

ostream & operator<<(ostream & out, const Vector &vetor) {
    out <<"[" << vetor(0);
    for(int i = 1 ; i < 3 ; i++)
        out << ", " << vetor(i);

    out << "]";
    return out;
}
