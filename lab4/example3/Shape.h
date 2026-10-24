#ifndef LAB4_SHAPE_H
#define LAB4_SHAPE_H
#include <iostream>
#include <string>


class Shape {
protected:
    std::string color;

    void printLabel(const std::string& shapeName) const {
        std::cout << shapeName << " [" << color << "]: ";
    }

public:
    explicit Shape(const std::string &color) : color(color) {
    }

    virtual void printArea() const = 0;
};


#endif //LAB4_SHAPE_H
