#ifndef LAB5_VECTOR2D_H
#define LAB5_VECTOR2D_H


class Vector2D {
private:
    double x, y;

public:
    Vector2D(double x = 0, double y = 0);

    Vector2D operator+(const Vector2D &other) const;

    Vector2D operator-(const Vector2D &other) const;

    Vector2D operator*(const double scalar) const;

    bool operator==(const Vector2D &other) const;

    bool operator!=(const Vector2D &other) const;

    double magnitude() const;

    void print() const;
};


#endif //LAB5_VECTOR2D_H
