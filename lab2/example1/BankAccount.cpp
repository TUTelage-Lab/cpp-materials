#include "BankAccount.h"

#include <iostream>

BankAccount::BankAccount(const std::string &owner, double balance) : owner(owner), balance(balance) {
}

void BankAccount::deposit(double amount) {
    this->balance += amount;
    std::cout << "Deposited balance is " << this->balance << std::endl;
}

void BankAccount::deposit(double amount, double fee) {
    this->balance += amount - fee;
    std::cout << "Deposited balance is " << this->balance << std::endl;
}

void BankAccount::deposit(double amount, double feePercent, bool isPrecent) {
    double fee = 0.0;

    if (isPrecent) {
        fee = amount * feePercent / 100.0;
    } else {
        fee = feePercent;
    }

    this->balance += amount - fee;
    std::cout << "Deposited balance is " << this->balance << std::endl;
}

double BankAccount::getBalance() const {
    return this->balance;
}

const std::string &BankAccount::getOwner() const {
    return this->owner;
}
