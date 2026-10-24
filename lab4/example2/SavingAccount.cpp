#include "SavingAccount.h"

#include <iostream>

SavingAccount::SavingAccount(const std::string& owner, const std::string& iban,
                             double amount, double interestRate, int lockMonths)
    : Account(owner, iban, amount), interestRate(interestRate), lockMonths(lockMonths) {}

void SavingAccount::applyInterest() {
    double interest = balance * interestRate / 100.0;
    balance += interest;
    std::cout << "Interest applied: " << interest << " . New balance: " << balance << "\n";
}

void SavingAccount::describe() const {
    Account::describe();
    std::cout << "  [Savings] Interest: " << interestRate << "%, lock period: " << lockMonths << " months.\n";
}
