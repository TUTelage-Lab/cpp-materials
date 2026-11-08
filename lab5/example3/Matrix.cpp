#include "Matrix.h"

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols) {
    data = new int[rows * cols]();
}

Matrix::Matrix(const Matrix &other) : rows(other.rows), cols(other.cols) {
    data = new int[rows * cols];
    for (int i = 0; i < rows * cols; i++) {
        data[i] = other.data[i];
    }
}

Matrix::~Matrix() {
    delete[] data;
}

int &Matrix::operator()(int r, int c) {
    if (r < 0 || r >= rows || c < 0 || c >= cols) {
        throw std::out_of_range("Matrix index out of range");
    }
    return data[r * cols + c];
}

const int &Matrix::operator()(int r, int c) const {
    if (r < 0 || r >= rows || c < 0 || c >= cols) {
        throw std::out_of_range("Matrix index out of range");
    }
    return data[r * cols + c];
}

Matrix &Matrix::operator=(const Matrix &other) {
    if (this == &other) {
        return *this;
    }
    delete[] data;
    rows = other.rows;
    cols = other.cols;
    data = new int[rows * cols];
    for (int i = 0; i < rows * cols; i++) {
        data[i] = other.data[i];
    }
    return *this;
}

Matrix &Matrix::operator+=(const Matrix &other) {
    for (int i = 0; i < rows * cols; i++) {
        data[i] += other.data[i];
    }
    return *this;
}

Matrix Matrix::operator+(const Matrix &other) const {
    Matrix result = *this;
    result += other;
    return result;
}

Matrix &Matrix::operator-=(const Matrix &other) {
    for (int i = 0; i < rows * cols; i++) {
        data[i] -= other.data[i];
    }
    return *this;
}

Matrix Matrix::operator-(const Matrix &other) const {
    Matrix result = *this;
    result -= other;
    return result;
}


Matrix &Matrix::operator*=(int scalar) {
    for (int i = 0; i < rows * cols; i++) {
        data[i] *= scalar;
    }
    return *this;
}

Matrix Matrix::operator*(int scalar) const {
    Matrix result = *this;
    result *= scalar;
    return result;
}

Matrix Matrix::operator*(const Matrix &other) const {
    Matrix result(rows, other.cols);
    for (int r = 0; r < rows; r++) {
        for (int k = 0; k < other.cols; k++) {
            for (int c = 0; c < cols; c++) {
                result(r, k) += data[r * cols + c] * other(c, k);
            }
        }
    }
    return result;
}

bool Matrix::operator==(const Matrix &other) const {
    if (rows != other.rows || cols != other.cols) {
        return false;
    }
    for (int i = 0; i < rows * cols; i++) {
        if (data[i] != other.data[i]) {
            return false;
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix &other) const {
    return !(*this == other);
}

std::ostream &operator<<(std::ostream &os, const Matrix &mat) {
    for (int r = 0; r < mat.rows; r++) {
        os << "[ ";
        for (int c = 0; c < mat.cols; c++) {
            os << mat.data[r * mat.cols + c];
            if (c < mat.cols - 1) os << "  ";
        }
        os << " ]\n";
    }
    return os;
}
