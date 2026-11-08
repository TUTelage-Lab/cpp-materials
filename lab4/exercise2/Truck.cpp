#include <iostream>
#include "Truck.h"


Truck::Truck(const std::string &licensePlate, const std::string &brand, int year,
             double fuelLevel, double fuelCapacity, double maxLoad)
    : Vehicle(licensePlate, brand, year, fuelLevel, fuelCapacity),
      maxLoad(maxLoad), currentLoad(0) {
}

bool Truck::load(double kg) {
    if (currentLoad + kg > maxLoad) {
        std::cout << licensePlate << ": load rejected — exceeds max load ("
                << maxLoad << "kg)\n";
        return false;
    }
    currentLoad += kg;
    std::cout << licensePlate << ": loaded " << kg << "kg — current load: "
            << currentLoad << "/" << maxLoad << "kg\n";
    return true;
}

void Truck::unload() {
    std::cout << licensePlate << ": unloaded " << currentLoad << "kg\n";
    currentLoad = 0;
}

void Truck::describe() const {
    Vehicle::describe();
    std::cout << "  [Truck] load: " << currentLoad << "/" << maxLoad << "kg\n";
}
