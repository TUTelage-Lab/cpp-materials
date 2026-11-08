#ifndef LAB5_COMPLEX_H
#define LAB5_COMPLEX_H

#include <iostream>

class Complex {
    double real;
    double imag;

public:
    Complex(double real = 0, double imag = 0);

    Complex operator+(const Complex &other) const;

    Complex operator-(const Complex &other) const;

    Complex operator*(const Complex &other) const;

    Complex operator/(const Complex &other) const;

    Complex operator-() const;

    bool operator==(const Complex &other) const;

    bool operator!=(const Complex &other) const;

    double magnitude() const;

    friend std::ostream &operator<<(std::ostream &os, const Complex &z);

    friend std::istream &operator>>(std::istream &is, Complex &z);
};

#endif //LAB5_COMPLEX_H
