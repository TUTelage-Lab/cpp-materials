#ifndef LAB4_VEHICLE_H
#define LAB4_VEHICLE_H
#include <string>

class Vehicle {
protected:
    std::string licensePlate;
    std::string brand;
    int year;
    double fuelLevel;
    double fuelCapacity;

public:
    Vehicle(const std::string &licensePlate, const std::string &brand,
            int year, double fuelLevel, double fuelCapacity);

    void refuel(double liters);

    bool canTravel(double km, double consumption) const;

    void describe() const;
};

#endif //LAB4_VEHICLE_H
