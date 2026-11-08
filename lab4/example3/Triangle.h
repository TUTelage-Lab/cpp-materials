#ifndef LAB4_TRIANGLE_H
#define LAB4_TRIANGLE_H
#include <cmath>
#include "Shape.h"


class Triangle : public Shape {
protected:
    double a, b, c;

public:
    Triangle(double a, double b, double c, const std::string &color)
        : Shape(color), a(a), b(b), c(c) {
    }

    double area() const override {
        double p = (a + b + c) / 2;
        return std::sqrt(p * (p - a) * (p - b) * (p - c));
    }

    void describe() const override {
        std::cout << "Triangle [" << color << "] a=" << a << ", b=" << b << ", c=" << c << ", area=" << area() << "\n";
    }
};


#endif //LAB4_TRIANGLE_H
