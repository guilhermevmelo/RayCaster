#ifndef PONTO_H
#define PONTO_H


class Point {
public:
    Point();
    Point(double, double, double);
    ~Point();

    inline double& operator()(int i) {
        return elements[i];
    };

    inline double operator()(int i) const {
        return elements[i];
    };
private:
    double elements[4];
};

#endif // PONTO_H
