#include <iostream>
#include <cmath>

#include "Triangle.h"

Triangle::Triangle(double a, double b, double c) {
    this->a = a;
    this->b = b;
    this->c = c;
}

double Triangle::face() const {
    const double halfParameter = (a + b + c) / 2;
    return sqrt(halfParameter * (halfParameter - a) * (halfParameter - b) * (halfParameter - c));
}

void Triangle::show(const char *name) const {
    std::cout << "Sides of a triangle: " << name << std::endl;
    std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;
}

Triangle::~Triangle() {
    std::cout << "Destructor of Triangle" << std::endl;
}
