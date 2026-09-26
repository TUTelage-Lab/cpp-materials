#include "Sensor.h"

#include <iostream>
#include <ostream>

Sensor::Sensor(double celsius) : celsius(celsius) {
}

double Sensor::read() const {
    return this->celsius;
}

double Sensor::read(char scale) const {
    switch (scale) {
        case 'F':
            return this->celsius * 9 / 5 + 32;
            break;
        case 'K':
            return this->celsius + 273.15;
            break;
        default:
            std::cout << "Unknown scale" << std::endl;
            exit(1);
    }
}

// TODO: Describe how this works, where it could be useful as well?
void Sensor::read(double &fahrenheit, double &kelvin) const {
    fahrenheit = this->read('F');
    kelvin = this->read('K');
}

void Sensor::describe() const {
    std::cout << "Temperature is: " << this->read() << " C" << std::endl;
}

void Sensor::describe(const std::string &location) const {
    std::cout << "[location]: " << location << " -- Temperature is: " << this->read() << " C" << std::endl;
}

void Sensor::describe(const std::string &location, char scale) const {
    std::cout << "[location]: " << location << " -- Temperature is: " << this->read(scale) << " " << scale << std::endl;
}
