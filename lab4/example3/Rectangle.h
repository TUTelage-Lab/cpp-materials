#ifndef LAB4_RECTANGLE_H
#define LAB4_RECTANGLE_H
#include <iostream>

#include "Shape.h"

class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double width, double height, const std::string &color)
        : Shape(color), width(width), height(height) {
    }

    void printArea() const override {
        printLabel("Rectangle");
        std::cout << width << "x" << height << ", area=" << width * height << "\n";
    }
};

#endif //LAB4_RECTANGLE_H
