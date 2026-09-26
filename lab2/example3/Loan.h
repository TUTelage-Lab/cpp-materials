#ifndef LAB2_LOAN_H
#define LAB2_LOAN_H

#include <string>

class BankAccount; // Predefined declaration to access friend declarations

class Loan {
private:
    std::string owner;
    double debt, interestRate;

public:
    Loan(const std::string &owner, double debt, double interestRate);

    friend void printFinancialSummary(const BankAccount &account, const Loan &loan);
};


#endif //LAB2_LOAN_H
