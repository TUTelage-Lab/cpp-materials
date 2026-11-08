#include "DynArray.h"
#include <stdexcept>

DynArray::DynArray(int capacity) : size(0), capacity(capacity) {
    data = new double[capacity]();
}

DynArray::DynArray(const DynArray &other) : size(other.size), capacity(other.capacity) {
    data = new double[capacity];
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

DynArray &DynArray::operator=(const DynArray &other) {
    if (this == &other) {
        return *this;
    }
    delete[] data;
    size = other.size;
    capacity = other.capacity;
    data = new double[capacity];
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
    return *this;
}

DynArray::~DynArray() {
    delete[] data;
}

void DynArray::push(double val) {
    if (size >= capacity) {
        throw std::overflow_error("DynArray is full");
    }
    data[size++] = val;
}

double &DynArray::operator[](int i) {
    if (i < 0 || i >= size) {
        throw std::out_of_range("DynArray index out of range");
    }
    return data[i];
}

const double &DynArray::operator[](int i) const {
    if (i < 0 || i >= size) {
        throw std::out_of_range("DynArray index out of range");
    }
    return data[i];
}

DynArray DynArray::operator+(const DynArray &other) const {
    DynArray result(size + other.size);
    for (int i = 0; i < size; i++) {
        result.push(data[i]);
    }
    for (int i = 0; i < other.size; i++) {
        result.push(other.data[i]);
    }
    return result;
}

bool DynArray::operator==(const DynArray &other) const {
    if (size != other.size) {
        return false;
    }
    for (int i = 0; i < size; i++) {
        if (data[i] != other.data[i]) {
            return false;
        }
    }
    return true;
}

bool DynArray::operator!=(const DynArray &other) const {
    return !(*this == other);
}

std::ostream &operator<<(std::ostream &os, const DynArray &arr) {
    os << "[";
    for (int i = 0; i < arr.size; i++) {
        os << arr.data[i];
        if (i < arr.size - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}
