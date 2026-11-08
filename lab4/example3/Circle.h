#ifndef LAB4_CIRCLE_H
#define LAB4_CIRCLE_H
#include "Shape.h"


class Circle : public Shape {
    double radius;

public:
    Circle(double radius, const std::string &color)
        : Shape(color), radius(radius) {
    }

    double area() const override { return M_PI * radius * radius; }

    void describe() const override {
        std::cout << "Circle  [" << color << "] radius=" << radius << ", area=" << area() << "\n";
    }
};

#endif //LAB4_CIRCLE_H
