#include "HourlyEmployee.h"

#include <iostream>

HourlyEmployee::HourlyEmployee(const std::string &name, const std::string &id,
                               int hours, double rate)
    : Employee(name, id), hoursWorked(hours), hourlyRate(rate) {
}

double HourlyEmployee::calcSalary() const { return hoursWorked * hourlyRate; }

void HourlyEmployee::printPayslip() const {
    std::cout << name << " [" << id << "] - hourly\n";
    std::cout << " Hours: " << hoursWorked
            << ", Rate: " << hourlyRate << "\n";
    std::cout << " Salary: " << calcSalary() << "\n";
}
