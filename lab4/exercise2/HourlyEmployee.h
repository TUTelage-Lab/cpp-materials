#ifndef LAB4_HOURLYEMPLOYEE_H
#define LAB4_HOURLYEMPLOYEE_H
#include "Employee.h"

class HourlyEmployee : public Employee {
private:
    double hourlyRate;

public:
    HourlyEmployee(const std::string &name, const std::string &id, double hourlyRate);

    double calcSalary() const override;
};

#endif //LAB4_HOURLYEMPLOYEE_H
