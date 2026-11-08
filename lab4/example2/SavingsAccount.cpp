#include "SavingsAccount.h"

#include <iostream>

SavingsAccount::SavingsAccount(const std::string &owner, const std::string &iban,
                               double initialBalance, double rate, int months)
    : Account(owner, iban, initialBalance), interestRate(rate), lockMonths(months) {
    std::cout << "SavingsAccount(\"" << owner << "\") constructor\n";
}

SavingsAccount::~SavingsAccount() {
    std::cout << "SavingsAccount(\"" << owner << "\") deconstructor\n";
}

void SavingsAccount::applyInterest() {
    double interest = balance * interestRate / 100.0;
    balance += interest;
    std::cout << "Interest: " << interest << " -- New Balance: " << balance << "\n";
}

void SavingsAccount::describe() const {
    Account::describe();
    std::cout << "  [Saving] Interest: " << interestRate << "%, months: " << lockMonths << "\n";
}
