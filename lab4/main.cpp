#include <iostream>

#include "example1/Dog.h"
#include "example2/CreditAccount.h"
#include "example2/SavingAccount.h"
#include "example3/Circle.h"
#include "example3/Rectangle.h"
#include "example3/RightTriangle.h"

static void callExample1();

static void callExample2();

static void callExample3();

int main() {
    // callExample1();
    // callExample2();
    callExample3();
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
