#include <iostream>

#include "example1/Dog.h"
#include "example2/CreditAccount.h"
#include "example2/SavingAccount.h"
#include "example3/Circle.h"
#include "example3/Rectangle.h"
#include "example3/RightTriangle.h"
#include "exercise1/Truck.h"
#include "exercise1/Bus.h"
#include "exercise2/HourlyEmployee.h"
#include "exercise2/SalariedEmployee.h"
#include "exercise2/CommissionEmployee.h"

static void callExample1();

static void callExample2();

static void callExample3();

static void callExercise1();

static void callExercise2();

int main() {
    // callExample1();
    // callExample2();
    // callExample3();
    callExercise1();
    callExercise2();
    return 0;
}

void callExample1() {
    const auto *dog = new Dog("Baklan", 3, "Kiril Kirilov", "huskey");
    dog->describe();
    delete dog;
}

void callExample2() {
    SavingAccount savings("Stefan Stambolov", "BG80BNBG96611020345678", 10000, 1.7, 12);
    CreditAccount credit("Stefan Stambolov", "BG80BNBG96611020345678", 10000, 2000);

    std::cout << "Info from saving account: " << std::endl;
    savings.describe();
    savings.deposit(2000);
    savings.applyInterest();
    std::cout << "\n" << std::endl;

    std::cout << "Info from credit account: " << std::endl;
    credit.describe();
    credit.withdraw(200);
    credit.withdraw(1000);
    credit.withdraw(9000);
    std::cout << "\n" << std::endl;
    credit.describe();
}

void callExample3() {
    const Circle circle(5, "blue");
    const Rectangle rectangle(5, 6, "blue");
    const RightTriangle triangle(3, 8, "blue");

    std::cout << "Info from shapes: " << std::endl;
    circle.printArea();
    rectangle.printArea();
    triangle.printArea();
}

void callExercise1() {
    Truck t1("CB1234AB", "Volvo", 2020, 200, 600, 15000);
    Truck t2("CB5678CD", "Scania", 2018, 100, 500, 20000);
    Bus b1("CB1111EF", "Mercedes", 2022, 150, 300, 50, "Sofia - Plovdiv");
    Bus b2("CB2222GH", "MAN", 2019, 80, 250, 40, "Sofia - Varna");

    t1.refuel(50);
    t1.load(8000);
    t1.load(10000);
    std::cout << "t1 can travel 300km (25L/100): " << (t1.canTravel(300, 25) ? "yes" : "no") << "\n";
    t1.describe();

    std::cout << "\n";

    t2.refuel(400);
    t2.load(20000);
    std::cout << "t2 can travel 500km (30L/100): " << (t2.canTravel(500, 30) ? "yes" : "no") << "\n";
    t2.describe();

    std::cout << "\n";

    b1.refuel(100);
    b1.boardPassengers(45);
    b1.boardPassengers(10);
    std::cout << "b1 can travel 150km (20L/100): " << (b1.canTravel(150, 20) ? "yes" : "no") << "\n";
    b1.describe();

    std::cout << "\n";

    b2.boardPassengers(30);
    b2.exitPassengers(10);
    std::cout << "b2 can travel 450km (22L/100): " << (b2.canTravel(450, 22) ? "yes" : "no") << "\n";
    b2.describe();
}

void callExercise2() {
    HourlyEmployee e1("Ivan Ivanov", "EMP001", 12.5);
    SalariedEmployee e2("Maria Georgieva", "EMP002", 3200.0);
    CommissionEmployee e3("Petar Petrov", "EMP003", 1500.0, 5.0);

    e1.logHours(160);
    e2.logHours(160);
    e3.logHours(160);
    e3.recordSale(20000);
    e3.recordSale(5000);

    e1.printPayslip();
    e2.printPayslip();
    e3.printPayslip();

    const Employee *employees[] = {&e1, &e2, &e3};
    const Employee *top = employees[0];
    for (const auto *e: employees) {
        if (e->calcSalary() > top->calcSalary()) {
            top = e;
        }
    }

    std::cout << "\nHighest salary this month:\n";
    top->printPayslip();
}
