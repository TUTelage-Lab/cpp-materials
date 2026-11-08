#include <iostream>

#include "example1/BankAccount.h"
#include "example2/SavingsAccount.h"
#include "example2/CreditAccount.h"
#include "example3/Circle.h"
#include "example3/Rectangle.h"
#include "example3/Triangle.h"
#include "example3/RightTriangle.h"
#include "example4/HourlyEmployee.h"
#include "example4/SalariedEmployee.h"
#include "example4/CommissionEmployee.h"
#include "exercise1/NAS.h"
#include "exercise2/Truck.h"
#include "exercise2/Bus.h"

static void callExample1();

static void callExample2();

static void callExample3();

static void callExample4();

static void callExercise1();

static void callExercise2();

int main() {
    callExample1();
    std::cout << "\n";
    callExample2();
    std::cout << "\n";
    callExample3();
    std::cout << "\n";
    callExample4();
    std::cout << "\n";
    callExercise1();
    std::cout << "\n";
    callExercise2();
    return 0;
}

void callExample1() {
    BankAccount acc("Asen Kukushev", 1000.0);
    acc.deposit(500.0);
    acc.withdraw(200.0);
    acc.withdraw(2000.0);
    std::cout << "Credit balance: " << acc.getBalance() << " \n";
}

void callExample2() {
    SavingsAccount savings("Marin Marinov", "BG80BNBG96611020345678", 10000.0, 3.5, 12);
    CreditAccount credit("Georgi Popov", "BG18RZBB91550123456789", 500.0, 2000.0);

    savings.describe();
    savings.deposit(2000.0);
    savings.applyInterest();

    credit.describe();
    credit.withdrawWithCredit(400.0);
    credit.withdrawWithCredit(300.0);
    credit.withdrawWithCredit(2000.0);
    std::cout << "\n";
    credit.describe();
}

void callExample3() {
    Circle c(5.0, "red");
    Rectangle r(4.0, 6.0, "blue");
    Triangle t(3.0, 4.0, 5.0, "green");
    RightTriangle rt(3.0, 4.0, 5.0, "white");

    Shape *shapes[4] = {&c, &r, &t, &rt};

    for (Shape *s: shapes) {
        s->describe();
    }

    double total = 0;
    for (Shape *s: shapes) {
        total += s->area();
    }
    std::cout << "\nTotal area: " << total << "\n";
}

void callExample4() {
    HourlyEmployee h("Kimon Georgiev", "E001", 168, 12.50);
    SalariedEmployee s("Atanas Burov", "E002", 3200.0);
    CommissionEmployee c("Boris Sakskoburggotski", "E003", 1500.0, 5.0);
    c.recordSale(18000.0);

    Employee *staff[3] = {&h, &s, &c};

    for (Employee *e: staff) {
        e->printPayslip();
        std::cout << "\n";
    }

    Employee *best = staff[0];
    for (Employee *e: staff) {
        if (e->calcSalary() > best->calcSalary()) {
            best = e;
        }
    }

    std::cout << "Max salaru: " << best->getName() << " - " << best->calcSalary() << "\n";
}

void callExercise1() {
    NAS nas1("HomeNAS", "Synology DS923+", "192.168.1.10", 1000, 16000.0, 5);
    NAS nas2("OfficeNAS", "QNAP TS-464", "192.168.1.20", 2500, 32000.0, 6);

    nas1.connect();
    nas1.write(4000.0);
    nas1.write(14000.0);

    nas2.connect();
    nas2.write(12000.0);

    std::cout << "\n";
    nas1.describe();
    nas1.status();
    std::cout << "\n";
    nas2.describe();
    nas2.status();

    std::cout << "\n";
    NAS *higher = nas1.powerConsumption() >= nas2.powerConsumption() ? &nas1 : &nas2;
    std::cout << "Higher power consumption: " << higher->powerConsumption() << "W\n";
}

void callExercise2() {
    Truck t1("CA1234AB", "Volvo", 2020, 200.0, 600.0, 20000.0);
    Truck t2("CB5678CD", "Scania", 2019, 100.0, 500.0, 15000.0);
    Bus b1("СА9999АА", "Mercedes", 2022, 150.0, 300.0, 50, "Line 1");
    Bus b2("СА1111ВВ", "Volvo", 2021, 80.0, 300.0, 40, "Line 7");

    t1.load(8000.0);
    t1.load(15000.0);
    t2.load(14000.0);
    t2.load(2000.0);

    b1.boardPassengers(45);
    b1.boardPassengers(10);
    b1.exitPassengers(20);
    b2.boardPassengers(38);

    t1.refuel(100.0);

    std::cout << "\n";
    Vehicle *fleet[4] = {&t1, &t2, &b1, &b2};
    for (Vehicle *v: fleet) {
        v->describe();
        std::cout << "  Can travel 200km (0.35L/km): " << (v->canTravel(200.0, 0.35) ? "yes" : "no") << "\n";
    }
}
