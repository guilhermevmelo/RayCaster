#ifndef ____Vetor__
#define ____Vetor__

#include <iostream>
#include <cmath>

class Vetor {
  public:
    Vetor();
    Vetor(double, double, double);
    ~Vetor();

    double comprimento();
    Vetor normalize();

    inline double& operator()(int i) {
        return elementos[i];
    };

    inline double operator()(int i) const {
        return elementos[i];
    };

  private:
    double elementos[4];
};

Vetor operator+(const Vetor &esquerda, const Vetor &direita);

Vetor operator-(const Vetor &esquerda, const Vetor &direita);

//Produto Escalar
double operator*(const Vetor &esquerda, const Vetor &direita);

//Produto Escalar por um Vetor
Vetor operator*(double escalar, const Vetor &vetor);
Vetor operator*(const Vetor &vetor, double escalar);

//Produto Vetorial
Vetor operator|(const Vetor &esquerda, const Vetor &direita);

//Usar para debugar
std::ostream& operator<<(std::ostream& out, const Vetor &vetor);

#endif /* defined(____Vetor__) */
