#ifndef LAB5_MATRIX_H
#define LAB5_MATRIX_H

#include <iostream>
#include <stdexcept>

class Matrix {
    int *data;
    int rows;
    int cols;

public:
    Matrix(int rows, int cols);

    Matrix(const Matrix &other);

    ~Matrix();

    int &operator()(int r, int c);

    const int &operator()(int r, int c) const;

    Matrix &operator=(const Matrix &other);

    Matrix &operator+=(const Matrix &other);

    Matrix operator+(const Matrix &other) const;

    Matrix &operator-=(const Matrix &other);

    Matrix operator-(const Matrix &other) const;

    Matrix &operator*=(int scalar);

    Matrix operator*(int scalar) const;

    Matrix operator*(const Matrix &other) const;

    bool operator==(const Matrix &other) const;

    bool operator!=(const Matrix &other) const;

    friend std::ostream &operator<<(std::ostream &os, const Matrix &mat);
};

#endif //LAB5_MATRIX_H
