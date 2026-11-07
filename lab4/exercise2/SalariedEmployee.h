#ifndef LAB4_SALARIEDEMPLOYEE_H
#define LAB4_SALARIEDEMPLOYEE_H
#include "Employee.h"

class SalariedEmployee : public Employee {
private:
    double monthlySalary;

public:
    SalariedEmployee(const std::string &name, const std::string &id, double monthlySalary);

    double calcSalary() const override;
};

#endif //LAB4_SALARIEDEMPLOYEE_H
