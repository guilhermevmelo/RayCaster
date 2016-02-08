#include "Color.h"

Color::~Color() {}

Color::Color() {}
Color::Color(double r, double g, double b) : r(r), g(g), b(b){ }

void Color::sanitize() {
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

Color operator+(const Color &a, const Color &b) {
  Color color(a.r + b.r, a.g + b.g, a.b + b.b);
  color.sanitize();
  return color;
}

Color operator*(const Color &a, const Color &b) {
  Color color(a.r * b.r, a.g * b.g, a.b * b.b);
  color.sanitize();
  return color;
}

Color operator*(double escalar, const Color &c) {
  Color color(escalar * c.r, escalar * c.g, escalar * c.b);
  color.sanitize();
  return color;
}

Color operator*(const Color &c, double scalar) {
  return scalar * c;
}
