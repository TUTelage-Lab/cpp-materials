#include <iostream>

#include "example1//Triangle.h"
#include "exercise1/Time.h"
#include "exercise2/Worker.h"
#include "exercise3/Line.h"

// Util function definitions
static void assignValidValue(double *var);

// Examples
static void callExample1();

// Exercises
static void callExercise1();

static void callExercise2();

static void callExercise3();

int main() {
    callExample1();
    callExercise1();
    callExercise2();
    callExercise3();
    return 0;
}

static void callExample1() {
    double a, b, c;

    assignValidValue(&a); // TODO: why & but not *
    assignValidValue(&b);
    assignValidValue(&c);

    std::cout << "Side a = " << a << "\nSide b = " << b << "\nSide c = " << c << std::endl << std::endl;

    // Object on the stack, accessed by name
    Triangle triangleStack(a, b, c);
    triangleStack.show("triangleStack");
    std::cout << "Area of triangle is: " << triangleStack.face() << std::endl << std::endl;

    // Object on the stack, copy-constructed from heap allocation (heap triangle is leaked — intentional demo)
    Triangle triangleStack2 = *new Triangle(a, b, c);
    triangleStack2.show("triangleStack2");
    std::cout << "Area of triangle is: " << triangleStack2.face() << std::endl << std::endl;

    // Object on the heap, accessed via pointer
    const auto *triangleHeap = new Triangle(a, b, c);
    triangleHeap->show("triangleHeap"); // TODO: Why -> but not *
    std::cout << "Area of triangle is: " << triangleHeap->face() << std::endl << std::endl;
    delete triangleHeap;
    std::cout << "Triangle destructor was called before method end!\n\n" << std::endl;
}

static void callExercise1() {
    Time t1;
    t1.setTime(13, 24, 7);
    t1.printTime();

    std::cout << std::endl;

    Time t2;
    t2.setTime(0, 0, 0);
    t2.printTime();

    std::cout << std::endl;

    Time t3;
    t3.setTime(11, 59, 59);
    t3.printTime();

    std::cout << std::endl;

    // Validation example - invalid values are rejected
    Time t4;
    t4.setTime(25, 61, 99);
    t4.printTime();
}

void callExercise2() {
    // Static object with dynamic array of salaries
    Worker stamat("001", "Stamat Harizanov");
    stamat.setPosition("Kazandzhia");
    stamat.setYearsOfService(14);
    std::cout << "Worker: " << stamat.getName()
            << "\n  ID: " << stamat.getId()
            << "\n  Position: " << stamat.getPosition()
            << "\n  Years: " << stamat.getYearsOfService() << std::endl;

    // Dynamic array (double*) — size known only at runtime
    double salaries1[] = {2000.0, 2500.0, 1800.0, 3000.0, 2200.0};
    stamat.setSalaries(salaries1, sizeof(salaries1) / sizeof(double));
    std::cout << "[dynamic] Avg salary: " << stamat.getAvgSalary() << std::endl;
    std::cout << "[dynamic] Min salary: " << stamat.getMinSalary() << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    // Dynamic object with static arrays of salaries
    auto *genadka = new Worker("002", "Genadka Kapinarska", "Hlebarka");
    genadka->setYearsOfService(12);
    std::cout << "Worker: " << genadka->getName()
            << "\n  ID: " << genadka->getId()
            << "\n  Position: " << genadka->getPosition()
            << "\n  Years: " << genadka->getYearsOfService() << std::endl;

    // Static array (double[120]) — size fixed at compile time, no heap allocation
    double salaries2[] = {4000.0, 4500.0, 3800.0, 5000.0, 4200.0, 4100.0};
    genadka->setSalariesArray(salaries2, 6);
    std::cout << "[static]  Avg salary: " << genadka->getAvgSalaryArray() << std::endl;
    std::cout << "[static]  Min salary: " << genadka->getMinSalaryArray() << std::endl;
    delete genadka;
}

static void callExercise3() {
    std::cout << "Drawing line with size 15:" << std::endl;
    Line l1(15);

    std::cout << std::endl;

    std::cout << "Drawing line with size 10:" << std::endl;
    auto *l2 = new Line(10);

    std::cout << std::endl;

    delete l2; // TODO: What if I just forgot, will it free the memory, when the program end?
}

static void assignValidValue(double *var) {
    do {
        std::cout << "Enter number > 0: ";
        std::cin >> *var;
    } while (*var <= 0);
}
