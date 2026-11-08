#include "Complex.h"
#include <cmath>
#include <stdexcept>

Complex::Complex(double real, double imag) : real(real), imag(imag) {
}

Complex Complex::operator+(const Complex &other) const {
    return {real + other.real, imag + other.imag};
}

Complex Complex::operator-(const Complex &other) const {
    return {real - other.real, imag - other.imag};
}

Complex Complex::operator*(const Complex &other) const {
    return {
        real * other.real - imag * other.imag,
        real * other.imag + imag * other.real
    };
}

Complex Complex::operator/(const Complex &other) const {
    double denom = other.real * other.real + other.imag * other.imag;
    if (denom == 0) {
        throw std::invalid_argument("Division by zero");
    }
    return {
        (real * other.real + imag * other.imag) / denom,
        (imag * other.real - real * other.imag) / denom
    };
}

Complex Complex::operator-() const {
    return {-real, -imag};
}

bool Complex::operator==(const Complex &other) const {
    return real == other.real && imag == other.imag;
}

bool Complex::operator!=(const Complex &other) const {
    return !(*this == other);
}

double Complex::magnitude() const {
    return std::sqrt(real * real + imag * imag);
}

std::ostream &operator<<(std::ostream &os, const Complex &z) {
    os << z.real;
    if (z.imag >= 0) {
        os << "+" << z.imag << "i";
    } else {
        os << z.imag << "i";
    }
    return os;
}

// expects: a+bi or a-bi
std::istream &operator>>(std::istream &is, Complex &z) {
    is >> z.real;
    char op;
    is >> op;
    is >> z.imag;
    char i;
    is >> i;
    if (op == '-') {
        z.imag = -z.imag;
    }
    return is;
}
