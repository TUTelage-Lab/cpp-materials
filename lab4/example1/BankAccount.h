#ifndef LAB4_BANKACCOUNT_H
#define LAB4_BANKACCOUNT_H
#include <string>


class BankAccount {
private:
    std::string owner;
    double balance;

public:
    BankAccount(const std::string &owner, double initialBalance);

    void deposit(double amount);

    bool withdraw(double amount);

    double getBalance() const;

    const std::string &getOwner() const;
};


#endif //LAB4_BANKACCOUNT_H
