#include <iostream>
#include "Vehicle.h"


Vehicle::Vehicle(const std::string &licensePlate, const std::string &brand, int year,
                 double fuelLevel, double fuelCapacity)
    : licensePlate(licensePlate), brand(brand), year(year),
      fuelLevel(fuelLevel), fuelCapacity(fuelCapacity) {
}

void Vehicle::refuel(double liters) {
    double space = fuelCapacity - fuelLevel;
    double added = (liters > space) ? space : liters;
    fuelLevel += added;
    std::cout << licensePlate << ": refueled " << added << "L — fuel: " << fuelLevel << "L\n";
}

bool Vehicle::canTravel(double km, double consumption) const {
    return fuelLevel >= km * consumption / 100.0;
}

void Vehicle::describe() const {
    std::cout << licensePlate << " | " << brand << " " << year
            << " | fuel: " << fuelLevel << "/" << fuelCapacity << "L\n";
}
