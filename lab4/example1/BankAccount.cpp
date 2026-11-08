#include "BankAccount.h"

#include <iostream>

BankAccount::BankAccount(const std::string &owner, double initialBalance)
    : owner(owner), balance(initialBalance) {
}

void BankAccount::deposit(double amount) {
    if (amount <= 0) {
        std::cout << "Invalid amount\n";
        return;
    }
    balance += amount;
    std::cout << "Deposit: " << amount << " -- Balance: " << balance << "\n";
}

bool BankAccount::withdraw(double amount) {
    if (amount <= 0 || amount > balance) {
        std::cout << "Not enough amount\n";
        return false;
    }
    balance -= amount;
    std::cout << "Withdrawn: " << amount << " -- Balance: " << balance << "\n";
    return true;
}

double BankAccount::getBalance() const {
    return balance;
}

const std::string &BankAccount::getOwner() const {
    return owner;
}
