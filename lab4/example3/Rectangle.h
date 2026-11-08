#ifndef LAB4_RECTANGLE_H
#define LAB4_RECTANGLE_H
#include "Shape.h"


class Rectangle : public Shape {
    double width, height;

public:
    Rectangle(double width, double height, const std::string &color)
        : Shape(color), width(width), height(height) {
    }

    double area() const override { return width * height; }

    void describe() const override {
        std::cout << "Rectangle [" << color << "] " << width << "x" << height << ", area=" << area() << "\n";
    }
};

#endif //LAB4_RECTANGLE_H
