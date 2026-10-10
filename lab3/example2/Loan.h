#ifndef LAB3_LOAN_H
#define LAB3_LOAN_H
#include <string>

class BankAccount;

class Loan {
private:
    std::string owner;
    double debt, interestRate;

public:
    Loan(const std::string &owner, double debt, double interestRate) : owner(owner), debt(debt),
                                                                       interestRate(interestRate) {
    };

    friend void printFinancialSummary(const BankAccount &acc, const Loan &loan);
};


#endif //LAB3_LOAN_H
