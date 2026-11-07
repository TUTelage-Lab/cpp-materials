#ifndef LAB4_COMMISSIONEMPLOYEE_H
#define LAB4_COMMISSIONEMPLOYEE_H
#include "Employee.h"

class CommissionEmployee : public Employee {
private:
    double baseSalary;
    double salesAmount;
    double commissionRate;

public:
    CommissionEmployee(const std::string &name, const std::string &id,
                       double baseSalary, double commissionRate);

    void recordSale(double amount);

    double calcSalary() const override;
};

#endif //LAB4_COMMISSIONEMPLOYEE_H
