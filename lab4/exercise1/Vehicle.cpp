#include <iostream>
#include "Vehicle.h"

Vehicle::Vehicle(const std::string &licensePlate, const std::string &brand,
                 int year, double fuelLevel, double fuelCapacity)
    : licensePlate(licensePlate), brand(brand), year(year),
      fuelLevel(fuelLevel), fuelCapacity(fuelCapacity) {
}

void Vehicle::refuel(double liters) {
    if (liters <= 0) {
        std::cout << "Invalid amount.\n";
        return;
    }
    double space = fuelCapacity - fuelLevel;
    double added = (liters > space) ? space : liters;
    fuelLevel += added;
    std::cout << "Refueled " << added << "L. Tank: " << fuelLevel << "/" << fuelCapacity << "L\n";
}

bool Vehicle::canTravel(double km, double consumption) const {
    return fuelLevel >= km * consumption / 100.0;
}

void Vehicle::describe() const {
    std::cout << licensePlate << " | " << brand << " (" << year
            << ") | Fuel: " << fuelLevel << "/" << fuelCapacity << "L\n";
}
