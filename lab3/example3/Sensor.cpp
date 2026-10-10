#include "Sensor.h"

#include <iostream>
#include <ostream>

Sensor::Sensor(const std::string &location, int capacity) : location(location), capacity(capacity) {
    this->readings = new double[capacity];
    std::cout << "Sensor for [ " << location << " ] is created" << std::endl;
}

Sensor::~Sensor() {
    delete[] readings;
    std::cout << "Sensor for [ " << location << " ] is destroyed" << std::endl;
}

double &Sensor::record(int i) {
    if (i < 0 || i >= capacity) {
        std::cout << "Error: index out of bounds" << std::endl;
        std::exit(1);
    }

    if (i >= count) {
        count = i + 1;
    }
    return readings[i];
}

const double &Sensor::get(int i) const {
    if (i < 0 || i >= count) {
        std::cout << "Error: index out of bounds" << std::endl;
        std::exit(1);
    }
    return readings[i];
}

void Sensor::print() const {
    std::cout << "Sensor for [ " << location << "]: => ";
    for (int i = 0; i < count; i++) {
        std::cout << readings[i] << (i < count - 1 ? ", " : "\n");
    }
}
