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
    Vector vector;
    double n = length();

    vector(0) = elements[0] / n;
    vector(1) = elements[1] / n;
    vector(2) = elements[2] / n;

    return vector;
}

Vector operator+(const Vector &left, const Vector &right) {
    Vector vector;

    vector(0) = left(0) + right(0);
    vector(1) = left(1) + right(1);
    vector(2) = left(2) + right(1);

    return vector;
}

Vector operator-(const Vector &left, const Vector &right) {
    Vector vector;

    vector(0) = left(0) - right(0);
    vector(1) = left(1) - right(1);
    vector(2) = left(2) - right(2);

    return vector;
}

Point operator+(const Point &point, const Vector &vector) {
    Point result;

    result(0) = point(0) + vector(0);
    result(1) = point(1) + vector(1);
    result(2) = point(2) + vector(1);

    return result;
}

Vector operator-(const Point &point, const Vector &vector) {
    Vector result;

    result(0) = point(0) - vector(0);
    result(1) = point(1) - vector(1);
    result(2) = point(2) - vector(1);

    return result;
}

Vector operator-(const Vector &vector, const Point &point) {
    return point - vector;
}

Point operator+(const Vector &vector, const Point &point) {
    return point + vector;
}

Vector operator-(const Point &left, const Point &right) {
    Vector vector;

    vector(0) = left(0) - right(0);
    vector(1) = left(1) - right(1);
    vector(2) = left(2) - right(2);

    return vector;
}

Vector operator-(const Vector &vector, const double x) {
    Vector r;

    r(0) = vector(0) - x;
    r(1) = vector(1) - x;
    r(2) = vector(2) - x;

    return vector;
}

double operator*(const Vector &esquerda, const Vector &direita) {
    return (esquerda(0) * direita(0)) + (esquerda(1) * direita(1)) + (esquerda(2) * direita(2));
}

double operator*(const Vector &vector, const Point &point) {
    return (vector(0) * point(0)) + (vector(1) * point(1)) + (vector(2) * point(2));
}

double operator*(const Point &point, const Vector &vector) {
    return vector * point;
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
    vetor(2) = esquerda(0) * direita(1) - esquerda(1) * direita(0);

    return vetor;
}

ostream & operator<<(ostream & out, const Vector &vetor) {
    out <<"[" << vetor(0);
    for(int i = 1 ; i < 3 ; i++)
        out << ", " << vetor(i);

    out << "]";
    return out;
}

ostream & operator<<(ostream & out, const Point &point) {
    out <<"[" << point(0);
    for(int i = 1 ; i < 3 ; i++)
        out << ", " << point(i);

    out << "]";
    return out;
}
