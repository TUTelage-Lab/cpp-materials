#include "BankAccount.h"

BankAccount::BankAccount(const std::string &owner, double balance) : owner(owner), balance(balance) {
    std::cout << "Create new BankAccount for " << owner << std::endl;
}

BankAccount::~BankAccount() {
    std::cout << "Delete BankAccount for " << owner << std::endl;
}

double BankAccount::getBalance() const {
    return balance;
}

const std::string &BankAccount::getOwner() const {
    return owner;
}

void BankAccount::deposit(double amount) {
    balance += amount;
}

void BankAccount::deposit(double amount, double fee) {
    balance += amount - fee;
}

void printByValues(BankAccount acc) {
    std::cout << "[by value] " << acc.getOwner()
            << ": " << acc.getBalance() << std::endl;
}

void printByRef(const BankAccount &acc) {
    std::cout << "[by ref] " << acc.getOwner()
            << ": " << acc.getBalance() << std::endl;
}
