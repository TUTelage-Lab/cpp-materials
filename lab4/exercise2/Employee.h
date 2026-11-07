#ifndef LAB4_EMPLOYEE_H
#define LAB4_EMPLOYEE_H
#include <string>

class Employee {
protected:
    std::string name;
    std::string id;
    int hoursWorked;

public:
    Employee(const std::string &name, const std::string &id);

    void logHours(int hours);

    virtual double calcSalary() const = 0;

    void printPayslip() const;
};

#endif //LAB4_EMPLOYEE_H
