#ifndef LAB4_CIRCLE_H
#define LAB4_CIRCLE_H
#include <iostream>

#include "Shape.h"

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double radius, const std::string &color) : Shape(color), radius(radius) {
    }

    void printArea() const override {
        printLabel("Circle");
        std::cout << "radius=" << radius << ", area=" << M_PI * radius * radius << "\n";
    }
};

#endif //LAB4_CIRCLE_H
