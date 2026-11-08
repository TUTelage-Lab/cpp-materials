#ifndef LAB5_POLYNOMIAL_H
#define LAB5_POLYNOMIAL_H
#include <iosfwd>

class Polynomial {
    double *coefficients;
    int degree;

public:
    Polynomial(int degree);

    Polynomial(const Polynomial &other);

    Polynomial &operator=(const Polynomial &other);

    ~Polynomial();

    double &operator[](int index);

    const double &operator[](int index) const;

    friend Polynomial operator+(const Polynomial &p1, const Polynomial &p2);

    friend std::ostream &operator<<(std::ostream &os, const Polynomial &p);
};

#endif //LAB5_POLYNOMIAL_H
