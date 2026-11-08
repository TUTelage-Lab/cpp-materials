#include "SalariedEmployee.h"

#include <iostream>

SalariedEmployee::SalariedEmployee(const std::string &name, const std::string &id,
                                   double salary)
    : Employee(name, id), monthlySalary(salary) {
}

double SalariedEmployee::calcSalary() const { return monthlySalary; }

void SalariedEmployee::printPayslip() const {
    std::cout << name << " [" << id << "] - salary\n";
    std::cout << " Salary: " << calcSalary() << "\n";
}
