#include "CommissionEmployee.h"

#include <iostream>

CommissionEmployee::CommissionEmployee(const std::string &name, const std::string &id,
                                       double base, double rate)
    : Employee(name, id), baseSalary(base), salesAmount(0), commissionRate(rate) {
}

void CommissionEmployee::recordSale(double amount) { salesAmount += amount; }

double CommissionEmployee::calcSalary() const {
    return baseSalary + salesAmount * commissionRate / 100.0;
}

void CommissionEmployee::printPayslip() const {
    std::cout << name << " [" << id << "] - commission\n";
    std::cout << "  Base: " << baseSalary
            << " sales: " << salesAmount
            << " (" << commissionRate << "%)\n";
    std::cout << "  Salary: " << calcSalary() << "\n";
}
