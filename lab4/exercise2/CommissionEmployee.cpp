#include "CommissionEmployee.h"

CommissionEmployee::CommissionEmployee(const std::string &name, const std::string &id,
                                       double baseSalary, double commissionRate)
    : Employee(name, id), baseSalary(baseSalary), salesAmount(0), commissionRate(commissionRate) {
}

void CommissionEmployee::recordSale(double amount) {
    if (amount > 0) salesAmount += amount;
}

double CommissionEmployee::calcSalary() const {
    return baseSalary + salesAmount * commissionRate / 100.0;
}
