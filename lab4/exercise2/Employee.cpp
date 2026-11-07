#include <iostream>
#include "Employee.h"

Employee::Employee(const std::string &name, const std::string &id)
    : name(name), id(id), hoursWorked(0) {
}

void Employee::logHours(int hours) {
    if (hours <= 0) return;
    int remaining = 240 - hoursWorked;
    int added = (hours > remaining) ? remaining : hours;
    hoursWorked += added;
}

void Employee::printPayslip() const {
    std::cout << "ID: " << id << " | " << name
            << " | Hours: " << hoursWorked
            << " | Salary: " << calcSalary() << " BGN\n";
}
