#ifndef ____Vetor__
#define ____Vetor__

#include <iostream>
#include <cmath>

class Vector {
  public:
    Vector();
    Vector(double, double, double);
    ~Vector();

    double comprimento();
    Vector normalize();

    inline double& operator()(int i) {
        return elementos[i];
    };

    inline double operator()(int i) const {
        return elementos[i];
    };

  private:
    double elementos[4];
};

Vector operator+(const Vector &esquerda, const Vector &direita);

Vector operator-(const Vector &esquerda, const Vector &direita);

//Produto Escalar
double operator*(const Vector &esquerda, const Vector &direita);

//Produto Escalar por um Vetor
Vector operator*(double escalar, const Vector &vetor);
Vector operator*(const Vector &vetor, double escalar);

//Produto Vetorial
Vector operator|(const Vector &esquerda, const Vector &direita);

//Usar para debugar
std::ostream& operator<<(std::ostream& out, const Vector &vetor);

#endif /* defined(____Vetor__) */
