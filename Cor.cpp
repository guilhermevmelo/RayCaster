#include "Cor.h"

Cor::~Cor() {}

Cor::Cor() {}
Cor::Cor(double r, double g, double b) : r(r), g(g), b(b){ }

void Cor::filtre() {
  if(r < 0.0 )
    r = 0.0;
  else if( r > 1.0 )
    r = 1.0;

  if(g < 0.0 )
    g = 0.0;
  else if( g > 1.0 )
    g = 1.0;

  if(b < 0.0)
    b = 0.0;
  else if(b > 1.0 )
    b = 1.0;
}

Cor operator+(const Cor &a, const Cor &b) {
  Cor cor(a.r + b.r, a.g + b.g, a.b + b.b);
  cor.filtre();
  return cor;
}

Cor operator*(const Cor &a, const Cor &b) {
  Cor cor(a.r * b.r, a.g * b.g, a.b * b.b);
  cor.filtre();
  return cor;
}

Cor operator*(double escalar, const Cor &c) {
  Cor cor(escalar * c.r, escalar * c.g, escalar * c.b);
  cor.filtre();
  return cor;
}
