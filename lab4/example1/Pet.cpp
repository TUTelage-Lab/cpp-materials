#include "Pet.h"

#include <iostream>

Pet::Pet(const std::string &name, int age, const std::string &owner)
    : Animal(name, age), owner(owner) {
    std::cout << "Pet(\"" << name << "\") created\n";
}

Pet::~Pet() {
    std::cout << "Pet(\"" << name << "\") destroyed\n";
}

void Pet::describe() const {
    Animal::describe();
    std::cout << "  Owner: " << owner << "\n";
}
