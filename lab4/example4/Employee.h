#ifndef LAB4_EX4_EMPLOYEE_H
#define LAB4_EX4_EMPLOYEE_H
#include <string>


class Employee {
protected:
    std::string name;
    std::string id;

public:
    Employee(const std::string &name, const std::string &id);

    virtual double calcSalary() const = 0;

    virtual void printPayslip() const;

    const std::string &getName() const;

    virtual ~Employee() = default;
};


#endif //LAB4_EX4_EMPLOYEE_H
