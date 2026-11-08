#ifndef LAB4_EX4_HOURLYEMPLOYEE_H
#define LAB4_EX4_HOURLYEMPLOYEE_H
#include "Employee.h"


class HourlyEmployee : public Employee {
    int hoursWorked;
    double hourlyRate;

public:
    HourlyEmployee(const std::string &name, const std::string &id,
                   int hours, double rate);

    double calcSalary() const override;

    void printPayslip() const override;
};


#endif //LAB4_EX4_HOURLYEMPLOYEE_H
