#ifndef ____vector__
#define ____vector__

#include <iostream>
#include <cmath>

class Vector {
  public:
    Vector();
    Vector(double, double, double);
    ~Vector();

    double length();
    Vector normalize();

    inline double& operator()(int i) {
        return elements[i];
    };

    inline double operator()(int i) const {
        return elements[i];
    };

  private:
    double elements[4];
};

Vector operator+(const Vector &left, const Vector &right);

Vector operator-(const Vector &left, const Vector &right);

//Produto Escalar
double operator*(const Vector &left, const Vector &right);

//Produto Escalar por um vector
Vector operator*(double escalar, const Vector &vector);
Vector operator*(const Vector &vector, double escalar);

//Produto vectorial
Vector operator|(const Vector &left, const Vector &right);

//Usar para debugar
std::ostream& operator<<(std::ostream& out, const Vector &vector);

#endif /* defined(____vector__) */
