#ifndef LAB4_ACCOUNT_H
#define LAB4_ACCOUNT_H
#include <string>


class Account {
protected:
    std::string owner, iban;
    double balance;

public:
    Account(const std::string& owner, const std::string& iban, double balance);

    void deposit(double amount);

    bool withdraw(double amount);

    double getBalance() const;

    void describe() const;
};


#endif //LAB4_ACCOUNT_H
