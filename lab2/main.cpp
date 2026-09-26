#include <iostream>

#include "example1/BankAccount.h"
#include "example2/Logger.h"
#include "example3/Loan.h"
#include "example4/Warehouse.h"

static void callExample1();

static void callExample2();

static void callExample3();

static void callExample4();

int main() {
    // callExample1();
    // callExample2();
    // callExample3();
    callExample4();
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
