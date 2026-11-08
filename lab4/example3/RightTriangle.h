#ifndef LAB4_RIGHTTRIANGLE_H
#define LAB4_RIGHTTRIANGLE_H
#include "Triangle.h"


class RightTriangle : public Triangle {
public:
    RightTriangle(double a, double b, double c, const std::string &color)
        : Triangle(a, b, c, color) {
    }

    double area() const override { return a * b / 2; }

    void describe() const override {
        std::cout << "RightTriangle [" << color << "] a=" << a << ", b=" << b << ", area=" << area() << "\n";
    }
};

#endif //LAB4_RIGHTTRIANGLE_H
