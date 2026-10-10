#ifndef LAB3_BANKACCOUNT_H
#define LAB3_BANKACCOUNT_H
#include <iostream>
#include <string>

class Loan; // TODO: this is for example 2

class BankAccount {
private:
    std::string owner;
    double balance;

public:
    BankAccount(const std::string &owner, double balance);

    ~BankAccount();

    double getBalance() const;

    const std::string &getOwner() const;

    void deposit(double amount);

    void deposit(double amount, double fee);

    friend void printFinancialSummary(const BankAccount &acc, const Loan &loan); // TODO: this is for example 2
};

void printByValues(BankAccount acc);

void printByRef(const BankAccount &acc);


#endif //LAB3_BANKACCOUNT_H
