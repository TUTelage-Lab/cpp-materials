#include <iostream>

#include "Line.h"

Line::Line(int length) {
    this->length = length;
    this->content = new char[length];
    for (int i = 0; i < length; i++) {
        content[i] = '*';
    }
    std::cout << content << std::endl;
}

Line::~Line() {
    std::cout << "Deleting line with size: " << this->length << std::endl;
    delete[] content;
}
