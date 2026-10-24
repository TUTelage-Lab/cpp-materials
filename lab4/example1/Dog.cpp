#include "Dog.h"

#include <iostream>

Dog::Dog(const std::string &name, int age, const std::string &owner, const std::string &breed)
    : Pet(name, age, owner), breed(breed) {
    std::cout << "Dog(\"" << name << "\") created\n";
}

Dog::~Dog() {
    std::cout << "Dog(\"" << name << "\") destroyed\n";
}

void Dog::describe() const {
    Pet::describe();
    std::cout << "  Breed: " << breed << "\n";
}
