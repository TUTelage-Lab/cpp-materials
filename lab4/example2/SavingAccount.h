#ifndef LAB4_SAVINGACCOUNT_H
#define LAB4_SAVINGACCOUNT_H
#include "Account.h"


class SavingAccount : public Account {
private:
    double interestRate;
    int lockMonths;

public:
    SavingAccount(const std::string& owner, const std::string& iban, double balance,
                  double interestRate, int lockMonths);

    void applyInterest();
    void describe() const;
};


#endif //LAB4_SAVINGACCOUNT_H
