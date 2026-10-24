#ifndef LAB4_RIGHTTRIANGLE_H
#define LAB4_RIGHTTRIANGLE_H
#include <iostream>

#include "Shape.h"

class RightTriangle : public Shape {
private:
    double base, height;

public:
    RightTriangle(double base, double height, const std::string &color)
        : Shape(color), base(base), height(height) {
    }

    void printArea() const override {
        printLabel("Right Triangle");
        std::cout << "base=" << base << ", height=" << height
                << ", area=" << 0.5 * base * height << "\n";
    }
};

#endif //LAB4_RIGHTTRIANGLE_H
