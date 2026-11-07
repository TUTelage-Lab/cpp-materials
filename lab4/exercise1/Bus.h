#ifndef LAB4_BUS_H
#define LAB4_BUS_H
#include "Vehicle.h"

class Bus : public Vehicle {
private:
    int maxPassengers;
    int currentPassengers;
    std::string route;

public:
    Bus(const std::string &licensePlate, const std::string &brand,
        int year, double fuelLevel, double fuelCapacity,
        int maxPassengers, const std::string &route);

    void boardPassengers(int n);

    void exitPassengers(int n);

    void describe() const;
};

#endif //LAB4_BUS_H
