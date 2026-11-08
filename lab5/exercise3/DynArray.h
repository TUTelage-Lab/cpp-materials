#ifndef LAB5_DYNARRAY_H
#define LAB5_DYNARRAY_H

#include <iostream>

class DynArray {
    double *data;
    int size;
    int capacity;

public:
    DynArray(int capacity);

    DynArray(const DynArray &other);

    DynArray &operator=(const DynArray &other);

    ~DynArray();

    void push(double val);

    double &operator[](int i);

    const double &operator[](int i) const;

    DynArray operator+(const DynArray &other) const;

    bool operator==(const DynArray &other) const;

    bool operator!=(const DynArray &other) const;

    friend std::ostream &operator<<(std::ostream &os, const DynArray &arr);
};

#endif //LAB5_DYNARRAY_H
