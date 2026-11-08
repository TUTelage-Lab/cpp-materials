#ifndef LAB4_SAVINGSACCOUNT_H
#define LAB4_SAVINGSACCOUNT_H
#include "Account.h"


class SavingsAccount : public Account {
private:
    double interestRate;
    int lockMonths;

public:
    SavingsAccount(const std::string &owner, const std::string &iban,
                   double initialBalance, double rate, int months);

    ~SavingsAccount();

    void applyInterest();

    void describe() const;
};


#endif //LAB4_SAVINGSACCOUNT_H
