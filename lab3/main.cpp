#include <iostream>

#include "example1/BankAccount.h"
#include "example2/Loan.h"
#include "example3/Sensor.h"
#include "exercise1/Student.h"
#include "exercise2/Student.h"
#include "exercise2/Course.h"


static void callExample1();

static void callExample2();

static void callExample3();

static void callExercise1();

static void callExercise2();


int main() {
    // callExample1();
    // callExample2();
    // callExample3();
    // callExercise1();
    // callExercise2();
    return 0;
}

static void callExample1() {
    BankAccount account("Temenuzhka Zhuzheva", 12500);
    account.deposit(2500);
    account.deposit(2500, 5);

    std::cout << std::endl;
    std::cout << "Print by Value" << std::endl;
    printByValues(account);

    std::cout << std::endl;
    std::cout << "Print by Reference" << std::endl;
    printByRef(account);

    std::cout << std::endl;
    std::cout << "Method ends here" << std::endl;
}

void printFinancialSummary(const BankAccount &acc, const Loan &loan) {
    const double netWorth = acc.balance - loan.debt;
    std::cout << "" << acc.owner << "\n";
    std::cout << "  Balance:       " << acc.balance << "\n";
    std::cout << "  Loan:          " << loan.debt
            << " (" << loan.interestRate << "% IR)\n";
    std::cout << "  Net Worth: " << netWorth << " \n";
}

static void callExample2() {
    const BankAccount account("Temenuzhka Zhuzheva", 12500);
    const Loan loan("Temenuzhka Zhuzheva", 60000, 3.3);

    printFinancialSummary(account, loan);
}

static void callExample3() {
    Sensor s("Nagasaki", 5);

    s.record(0) = 22.5;
    s.record(1) = 23.1;
    s.record(2) = 21.8;
    s.record(3) = 3887;
    s.record(4) = 22.9;

    s.print();

    std::cout << "Value [3]: " << s.get(3) << std::endl;
}

static void summarize(const ex1::Student &student) {
    student.print();
}

static void callExercise1() {
    const auto student1 = new ex1::Student("Goshko", "121221002");
    student1->addGrade(4.5);
    student1->addGrade(5.4);
    student1->addGrade(3.6);

    const auto student2 = new ex1::Student("Toshko", "121221001");
    student2->addGrade(4.4);
    student2->addGrade(5.2);
    student2->addGrade(3.3);

    const auto student3 = new ex1::Student("Boshko", "121221003");
    student3->addGrade(3);
    student3->addGrade(4.1);
    student3->addGrade(5.5);

    ex1::Student *students[] = {student1, student2, student3};

    // Get best by average
    ex1::Student *best = students[0];
    for (const auto student: students) {
        if (student->getAverage() > best->getAverage()) {
            best = student;
        }
    }
    best->print();
    best->getBest() += 0.25;

    summarize(*best);

    std::cout << "\n\nAll students: \n";
    for (const auto student: students) {
        student->print();
    }

    delete student1;
    delete student2;
    delete student3;
}

static void callExercise2() {
    const auto student1 = new ex2::Student("Denis", "121221010");
    const auto student2 = new ex2::Student("Dvenis", "121221011");
    const auto student3 = new ex2::Student("Trenis", "121221012");

    ex2::Course math("Mathematics", 3);
    ex2::Course physics("Physics", 3);

    math.enroll(*student1);
    math.enroll(*student2);
    math.enroll(*student3);

    std::cout << "Before transfer\n";
    printReport(math);
    printReport(physics);

    transfer(*student2, math, physics);

    std::cout << "\nAfter transfer\n";
    printReport(math);
    printReport(physics);

    std::cout << "\ngetEnrolled demo\n";
    const ex2::Student &enrolled = math.getEnrolled(0);
    std::cout << "First enrolled in Mathematics: " << enrolled.getName() << "\n";

    delete student1;
    delete student2;
    delete student3;
}
