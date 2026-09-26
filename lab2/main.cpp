#include <iostream>

#include "example1/BankAccount.h"
#include "example2/Logger.h"
#include "example3/Loan.h"
#include "example4/Warehouse.h"
#include "exercise1/Sensor.h"
#include "exercise2/Course.h"
#include "exercise2/Student.h"

static void callExample1();

static void callExample2();

static void callExample3();

static void callExample4();

static void callExercise1();

static void callExercise2();

int main() {
    // Examples
    callExample1();
    callExample2();
    callExample3();
    callExample4();

    // Exercises
    callExercise1();
    callExercise2();

    return 0;
}

static void callExample1() {
    BankAccount account("Franco Garsia Dolorez Mateo Percival de la Cruz", 1000);

    std::cout << account.getOwner() << " operations are: " << std::endl;
    account.deposit(500);
    account.deposit(200, 5);
    account.deposit(300, 2, true);
    account.deposit(400, 10, false);
}

static void callExample2() {
    Logger logger("APP");

    logger.log("Starting app");
    logger.log(200);
    logger.log("Connection Error", 503);
    logger.log("Consumed memory (MB)", 128.5);
}

void printFinancialSummary(const BankAccount &acc, const Loan &loan) {
    double netWorth = acc.balance - loan.debt;
    std::cout << "Summary: " << acc.owner << std::endl;
    std::cout << "  Balance: " << acc.balance << std::endl;
    std::cout << "  Debt: " << loan.debt << " (" << loan.interestRate << "% interest)" << std::endl;
    std::cout << "  Net Worth: " << netWorth << std::endl;
}

static void callExample3() {
    BankAccount account("Stamat Dzhurov", 5000);
    Loan loan("Stamat Dzhurov", 12000, 4.5);

    printFinancialSummary(account, loan);
}

static void callExample4() {
    Warehouse w1("Stuff and Staff Sofia", 340, 85000);
    Warehouse w2("Stuff and Staff Plovdiv", 120, 22000);
    Audit auditor("Magdanoz Gergiev");

    auditor.inspect(w1);
    std::cout << std::endl;
    auditor.inspect(w2);
}

static void callExercise1() {
    auto const &sensor = new Sensor(23.4);

    std::cout << "Sensor is initialized" << std::endl;
    sensor->describe();
    sensor->describe("Lotharingia");
    sensor->describe("Lotharingia", 'F');
    sensor->describe("Lotharingia", 'K');
    sensor->describe("Lotharingia", 'D');
}

void enroll(Student &student, Course &course) {
    if (course.currentStudents < course.maxStudents) {
        course.currentStudents++;
        std::cout <<
                "Student: " << student.name <<
                "\nFaculty Number: " << student.facultyNumber <<
                "\nIs enrolled in course: " << course.title << std::endl;
        return;
    }
    std::cout << "Student is not enrolled in course due to full capacity." << std::endl;
}

static void callExercise2() {
    Student s1("Kalin", "121221001");
    Student s3("Boyana", "121221002");
    Student s2("Marin", "121221003");

    Course c("Vampire Hypnosis", 5, 3);

    auto *registrar = new Registrar();
    registrar->printReport(c);
    std::cout << std::endl;
    std::cout << std::endl;
    enroll(s1, c);
    std::cout << std::endl;
    enroll(s2, c);
    std::cout << std::endl;
    enroll(s3, c);

    registrar->printReport(c);
    delete registrar;
}
