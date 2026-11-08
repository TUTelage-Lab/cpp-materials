#ifndef LAB4_EX4_SALARIEDEMPLOYEE_H
#define LAB4_EX4_SALARIEDEMPLOYEE_H
#include "Employee.h"


class SalariedEmployee : public Employee {
    double monthlySalary;

public:
    SalariedEmployee(const std::string &name, const std::string &id, double salary);

    double calcSalary() const override;

    void printPayslip() const override;
};


#endif //LAB4_EX4_SALARIEDEMPLOYEE_H
