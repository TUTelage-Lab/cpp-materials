#include <iostream>
#include "Bus.h"


Bus::Bus(const std::string &licensePlate, const std::string &brand, int year,
         double fuelLevel, double fuelCapacity, int maxPassengers,
         const std::string &route)
    : Vehicle(licensePlate, brand, year, fuelLevel, fuelCapacity),
      maxPassengers(maxPassengers), currentPassengers(0), route(route) {
}

void Bus::boardPassengers(int n) {
    int available = maxPassengers - currentPassengers;
    int boarded = (n > available) ? available : n;
    currentPassengers += boarded;
    std::cout << licensePlate << ": boarded " << boarded << " — passengers: "
            << currentPassengers << "/" << maxPassengers << "\n";
}

void Bus::exitPassengers(int n) {
    int left = (n > currentPassengers) ? currentPassengers : n;
    currentPassengers -= left;
    std::cout << licensePlate << ": exited " << left << " — passengers: "
            << currentPassengers << "/" << maxPassengers << "\n";
}

void Bus::describe() const {
    Vehicle::describe();
    std::cout << "  [Bus] route: " << route << " | passengers: "
            << currentPassengers << "/" << maxPassengers << "\n";
}
