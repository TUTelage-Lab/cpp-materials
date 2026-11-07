#ifndef LAB4_TRUCK_H
#define LAB4_TRUCK_H
#include "Vehicle.h"

class Truck : public Vehicle {
private:
    double maxLoad;
    double currentLoad;

public:
    Truck(const std::string &licensePlate, const std::string &brand,
          int year, double fuelLevel, double fuelCapacity, double maxLoad);

    bool load(double kg);

    void unload();

    void describe() const;
};

#endif //LAB4_TRUCK_H
