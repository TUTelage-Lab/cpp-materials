#ifndef LAB5_CIRCULARBUFFER_H
#define LAB5_CIRCULARBUFFER_H

#include <iostream>

class CircularBuffer {
    double *data;
    int capacity;
    int head;
    int count;

public:
    CircularBuffer(int capacity);

    CircularBuffer(const CircularBuffer &other);

    CircularBuffer &operator=(const CircularBuffer &other);

    ~CircularBuffer();

    void push(double val);

    double &operator[](int i);

    const double &operator[](int i) const;

    friend std::ostream &operator<<(std::ostream &os, const CircularBuffer &buf);
};

#endif //LAB5_CIRCULARBUFFER_H
