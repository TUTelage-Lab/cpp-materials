#ifndef LAB5_LOGGEDPTR_H
#define LAB5_LOGGEDPTR_H

#include <iostream>

template<typename T>
class LoggedPtr {
    T *ptr;

public:
    explicit LoggedPtr(T *p = nullptr) : ptr(p) {
    }

    ~LoggedPtr() {
        delete ptr;
    }

    LoggedPtr &operator=(LoggedPtr &other) {
        if (this == &other) {
            return *this;
        }
        delete ptr;
        ptr = other.ptr;
        other.ptr = nullptr;
        return *this;
    }

    T *operator->() {
        std::cout << "[LoggedPtr] -> accessed: " << ptr << "\n";
        return ptr;
    }

    T &operator*() {
        return *ptr;
    }
};

#endif //LAB5_LOGGEDPTR_H
