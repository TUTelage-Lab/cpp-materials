#include "Account.h"

#include <iostream>

Account::Account(const std::string &owner, const std::string &iban, double initialBalance)
    : owner(owner), iban(iban), balance(initialBalance) {
    std::cout << "Account(\"" << owner << "\") constructor\n";
}

Account::~Account() {
    std::cout << "Account(\"" << owner << "\") deconstructor\n";
}

void Account::deposit(double amount) {
    if (amount <= 0) {
        std::cout << "Invalid amount\n";
        return;
    }
    balance += amount;
    std::cout << "Deposit: " << amount << " -- Balance: " << balance << "\n";
}

bool Account::withdraw(double amount) {
    if (amount <= 0 || amount > balance) {
        std::cout << "Недостатъчна наличност.\n";
        return false;
    }
    balance -= amount;
    std::cout << "Withdrawn: " << amount << " -- Balance: " << balance << "\n";
    return true;
}

void Account::describe() const {
    std::cout << "IBAN: " << iban << "  |  Owner: " << owner << "  |  Balance: " << balance << "\n";
}
