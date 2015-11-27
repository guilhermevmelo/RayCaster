#ifndef ____Cor__
#define ____Cor__

class Cor {

public:
    double r, g, b;

    Cor();
    Cor(double r, double g, double b);
    ~Cor();
    void filtre();
};

Cor operator+(const Cor &a, const Cor &b);
Cor operator*(const Cor &a, const Cor &b);
Cor operator*(double escalar, const Cor &c);


#endif /* defined(____Cor__) */
