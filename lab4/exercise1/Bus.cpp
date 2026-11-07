#include <iostream>
#include "Bus.h"

Bus::Bus(const std::string &licensePlate, const std::string &brand,
         int year, double fuelLevel, double fuelCapacity,
         int maxPassengers, const std::string &route)
    : Vehicle(licensePlate, brand, year, fuelLevel, fuelCapacity),
      maxPassengers(maxPassengers), currentPassengers(0), route(route) {
}

void Bus::boardPassengers(int n) {
    int free = maxPassengers - currentPassengers;
    int boarded = (n > free) ? free : n;
    currentPassengers += boarded;
    std::cout << boarded << " passengers boarded. On bus: " << currentPassengers << "\n";
}

void Bus::exitPassengers(int n) {
    int left = (n > currentPassengers) ? currentPassengers : n;
    currentPassengers -= left;
    std::cout << left << " passengers exited. On bus: " << currentPassengers << "\n";
}

void Bus::describe() const {
    Vehicle::describe();
    std::cout << "  [Bus] Route: " << route
            << " | Passengers: " << currentPassengers << "/" << maxPassengers << "\n";
}
