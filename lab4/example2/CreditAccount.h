#ifndef LAB4_CREDITACCOUNT_H
#define LAB4_CREDITACCOUNT_H
#include "Account.h"


class CreditAccount : public Account {
private:
    double creditLimit, usedCredit;

public:
    CreditAccount(const std::string& owner, const std::string& iban,
                  double initialBalance, double limit);

    bool withdraw(double amount);

    void describe() const;
};


#endif //LAB4_CREDITACCOUNT_H
