#include "Vector2D.h"

#include <cmath>
#include <iostream>

Vector2D::Vector2D(double x, double y) : x(x), y(y) {
}

Vector2D Vector2D::operator+(const Vector2D &other) const {
    return {x + other.x, y + other.y};
}

Vector2D Vector2D::operator-(const Vector2D &other) const {
    return {x - other.x, y - other.y};
}

Vector2D Vector2D::operator*(const double scalar) const {
    return {x * scalar, y * scalar};
}

bool Vector2D::operator==(const Vector2D &other) const {
    return x == other.x && y == other.y;
}

bool Vector2D::operator!=(const Vector2D &other) const {
    return !(*this == other);
}

double Vector2D::magnitude() const {
    return std::sqrt(x * x + y * y);
}


void Vector2D::print() const {
    std::cout << "(" << x << ", " << y << ")";
}
