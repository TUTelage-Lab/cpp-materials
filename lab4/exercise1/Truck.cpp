#include <iostream>
#include "Truck.h"

Truck::Truck(const std::string &licensePlate, const std::string &brand,
             int year, double fuelLevel, double fuelCapacity, double maxLoad)
    : Vehicle(licensePlate, brand, year, fuelLevel, fuelCapacity),
      maxLoad(maxLoad), currentLoad(0) {
}

bool Truck::load(double kg) {
    if (kg <= 0 || currentLoad + kg > maxLoad) {
        std::cout << "Cannot load " << kg << "kg (limit: " << maxLoad << "kg)\n";
        return false;
    }
    currentLoad += kg;
    std::cout << "Loaded " << kg << "kg. Total: " << currentLoad << "/" << maxLoad << "kg\n";
    return true;
}

void Truck::unload() {
    currentLoad = 0;
    std::cout << "Truck unloaded.\n";
}

void Truck::describe() const {
    Vehicle::describe();
    std::cout << "  [Truck] Load: " << currentLoad << "/" << maxLoad << "kg\n";
}
