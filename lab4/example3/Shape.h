#ifndef LAB4_SHAPE_H
#define LAB4_SHAPE_H
#include <iostream>
#include <string>


class Shape {
protected:
    std::string color;

public:
    explicit Shape(const std::string &color);

    virtual double area() const = 0;

    virtual void describe() const {
        std::cout << "Shape [" << color << "], area=" << area() << "\n";
    }

    virtual ~Shape() = default;
};


#endif //LAB4_SHAPE_H
