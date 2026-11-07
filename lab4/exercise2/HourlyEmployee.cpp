#include "HourlyEmployee.h"

HourlyEmployee::HourlyEmployee(const std::string &name, const std::string &id, double hourlyRate)
    : Employee(name, id), hourlyRate(hourlyRate) {
}

double HourlyEmployee::calcSalary() const {
    return hoursWorked * hourlyRate;
}
