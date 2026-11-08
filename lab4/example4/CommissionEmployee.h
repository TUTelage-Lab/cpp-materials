#ifndef LAB4_EX4_COMMISSIONEMPLOYEE_H
#define LAB4_EX4_COMMISSIONEMPLOYEE_H
#include "Employee.h"


class CommissionEmployee : public Employee {
    double baseSalary;
    double salesAmount;
    double commissionRate;

public:
    CommissionEmployee(const std::string &name, const std::string &id,
                       double base, double rate);

    void recordSale(double amount);

    double calcSalary() const override;

    void printPayslip() const override;
};


#endif //LAB4_EX4_COMMISSIONEMPLOYEE_H
