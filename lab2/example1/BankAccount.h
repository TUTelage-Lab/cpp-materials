#ifndef LAB2_BANKACCOUNT_H
#define LAB2_BANKACCOUNT_H

#include <string>

class Loan; // TODO: predefined declaration used for example 3

class BankAccount {
private:
    std::string owner;
    double balance;

public:
    BankAccount(const std::string &owner, double balance);

    void deposit(double amount);

    void deposit(double amount, double fee);

    void deposit(double amount, double feePercent, bool isPrecent);

    double getBalance() const;

    const std::string &getOwner() const;

    // TODO: independent friendly function used for example 3
    friend void printFinancialSummary(const BankAccount &account, const Loan &loan);
};


#endif //LAB2_BANKACCOUNT_H
