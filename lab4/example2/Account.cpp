#include "Account.h"

#include <iostream>

Account::Account(const std::string& owner, const std::string& iban, double balance)
    : owner(owner), iban(iban), balance(balance) {}

void Account::deposit(double amount) {
    if (amount <= 0) { std::cout << "Invalid amount.\n"; return; }
    balance += amount;
    std::cout << "Deposited " << amount << " . Balance: " << balance << " \n";
}

bool Account::withdraw(double amount) {
    if (amount <= 0 || amount > balance) {
        std::cout << "Insufficient funds.\n";
        return false;
    }
    balance -= amount;
    std::cout << "Withdrawn " << amount << " . Balance: " << balance << " \n";
    return true;
}

double Account::getBalance() const {
    return balance;
}

void Account::describe() const {
    std::cout << "IBAN: " << iban << "  |  Титуляр: " << owner
              << "  |  Balance: " << balance << "\n";
}
