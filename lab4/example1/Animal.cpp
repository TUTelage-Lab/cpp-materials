#include "Animal.h"

#include <iostream>

Animal::Animal(const std::string &name, int age) : name(name), age(age) {
    std::cout << "Animal(\"" << name << "\") created\n";
}

Animal::~Animal() {
    std::cout << "Animal(\"" << name << "\") destroyed\n";
}

void Animal::describe() const {
    std::cout << "Name: " << name << ", age: " << age << " г.\n";
}
