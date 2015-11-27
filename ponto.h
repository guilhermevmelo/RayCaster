#ifndef PONTO_H
#define PONTO_H


class Ponto {
public:
    Ponto();
    Ponto(double, double, double);
    ~Ponto();

    inline double& operator()(int i) {
        return elementos[i];
    };

    inline double operator()(int i) const {
        return elementos[i];
    };
private:
    double elementos[4];
};

#endif // PONTO_H
