#include "Employee.h"

#include <iostream>

Employee::Employee(const std::string &name, const std::string &id)
    : name(name), id(id) {
}

void Employee::printPayslip() const {
    std::cout << "" << name << " [" << id << "]\n";
    std::cout << "  Salary: " << calcSalary() << "\n";
}

const std::string &Employee::getName() const { return name; }
