#include "SalariedEmployee.h"

SalariedEmployee::SalariedEmployee(const std::string &name, const std::string &id, double monthlySalary)
    : Employee(name, id), monthlySalary(monthlySalary) {
}

double SalariedEmployee::calcSalary() const {
    return monthlySalary;
}
