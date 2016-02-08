#ifndef ____Cor__
#define ____Cor__

class Color {

public:
    double r, g, b;

    Color();
    Color(double r, double g, double b);
    ~Color();
    void sanitize();
};

Color operator+(const Color &a, const Color &b);
Color operator*(const Color &a, const Color &b);
Color operator*(double scalar, const Color &c);
Color operator*(const Color &c, double scalar);


#endif /* defined(____Cor__) */
