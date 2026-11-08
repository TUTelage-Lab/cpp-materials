#ifndef LAB5_FRACTION_H
#define LAB5_FRACTION_H


class Fraction {
private:
    int numerator, denominator;

    void reduce();

public:
    explicit Fraction(int numerator = 0, int denominator = 1);

    Fraction operator+(const Fraction &other) const;

    Fraction operator-(const Fraction &other) const;

    Fraction operator*(const Fraction &other) const;

    Fraction operator/(const Fraction &other) const;

    bool operator==(const Fraction &other) const;

    void print() const;
};


#endif //LAB5_FRACTION_H
