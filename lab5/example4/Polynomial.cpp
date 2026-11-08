#include "Polynomial.h"
#include <iostream>
#include <stdexcept>
#include <cmath>

Polynomial::Polynomial(int degree) : degree(degree) {
    coefficients = new double[degree + 1]();
}

Polynomial::Polynomial(const Polynomial &other) : degree(other.degree) {
    coefficients = new double[degree + 1];
    for (int i = 0; i <= degree; i++)
        coefficients[i] = other.coefficients[i];
}

Polynomial &Polynomial::operator=(const Polynomial &other) {
    if (this == &other) return *this;
    delete[] coefficients;
    degree = other.degree;
    coefficients = new double[degree + 1];
    for (int i = 0; i <= degree; i++)
        coefficients[i] = other.coefficients[i];
    return *this;
}

Polynomial::~Polynomial() {
    delete[] coefficients;
}

double &Polynomial::operator[](int index) {
    if (index < 0 || index > degree)
        throw std::out_of_range("Polynomial index out of range");
    return coefficients[index];
}

const double &Polynomial::operator[](int index) const {
    if (index < 0 || index > degree)
        throw std::out_of_range("Polynomial index out of range");
    return coefficients[index];
}

Polynomial operator+(const Polynomial &p1, const Polynomial &p2) {
    int maxDeg = p1.degree > p2.degree ? p1.degree : p2.degree;
    Polynomial result(maxDeg);
    for (int i = 0; i <= p1.degree; i++) result.coefficients[i] += p1.coefficients[i];
    for (int i = 0; i <= p2.degree; i++) result.coefficients[i] += p2.coefficients[i];
    return result;
}

std::ostream &operator<<(std::ostream &os, const Polynomial &p) {
    bool first = true;
    for (int i = p.degree; i >= 0; i--) {
        if (p.coefficients[i] == 0) {
            continue;
        }
        double abs_c = std::abs(p.coefficients[i]);
        if (!first) {
            os << (p.coefficients[i] > 0 ? " + " : " - ");
        } else if (p.coefficients[i] < 0) {
            os << "-";
        }
        if (i == 0) {
            os << abs_c;
        } else if (i == 1) {
            os << abs_c << "x";
        } else {
            os << abs_c << "x^" << i;
        }
        first = false;
    }
    if (first) {
        os << "0";
    }
    return os;
}
