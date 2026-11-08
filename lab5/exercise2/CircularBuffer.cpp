#include "CircularBuffer.h"
#include <stdexcept>

CircularBuffer::CircularBuffer(int capacity) : capacity(capacity), head(0), count(0) {
    data = new double[capacity]();
}

CircularBuffer::CircularBuffer(const CircularBuffer &other)
    : capacity(other.capacity), head(other.head), count(other.count) {
    data = new double[capacity];
    for (int i = 0; i < capacity; i++) {
        data[i] = other.data[i];
    }
}

CircularBuffer &CircularBuffer::operator=(const CircularBuffer &other) {
    if (this == &other) {
        return *this;
    }
    delete[] data;
    capacity = other.capacity;
    head = other.head;
    count = other.count;
    data = new double[capacity];
    for (int i = 0; i < capacity; i++) {
        data[i] = other.data[i];
    }
    return *this;
}

CircularBuffer::~CircularBuffer() {
    delete[] data;
}

void CircularBuffer::push(double val) {
    data[head] = val;
    head = (head + 1) % capacity;
    if (count < capacity) {
        count++;
    }
}

double &CircularBuffer::operator[](int i) {
    if (i < 0 || i >= count) {
        throw std::out_of_range("CircularBuffer index out of range");
    }
    int physical = (head - 1 - i + capacity) % capacity;
    return data[physical];
}

const double &CircularBuffer::operator[](int i) const {
    if (i < 0 || i >= count) {
        throw std::out_of_range("CircularBuffer index out of range");
    }
    int physical = (head - 1 - i + capacity) % capacity;
    return data[physical];
}

std::ostream &operator<<(std::ostream &os, const CircularBuffer &buf) {
    os << "[";
    for (int i = 0; i < buf.count; i++) {
        os << buf[i];
        if (i < buf.count - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}
