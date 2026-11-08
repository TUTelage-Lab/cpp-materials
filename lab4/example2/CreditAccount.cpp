#include "CreditAccount.h"

#include <iostream>

CreditAccount::CreditAccount(const std::string &owner, const std::string &iban,
                             double initialBalance, double limit)
    : Account(owner, iban, initialBalance), creditLimit(limit), usedCredit(0) {
    std::cout << "CreditAccount(\"" << owner << "\") constructor\n";
}

CreditAccount::~CreditAccount() {
    std::cout << "CreditAccount(\"" << owner << "\") deconstructor\n";
}

bool CreditAccount::withdrawWithCredit(double amount) {
    double available = balance + (creditLimit - usedCredit);
    if (amount > available) {
        std::cout << "Invalid credit limit\n";
        return false;
    }
    if (amount <= balance) {
        return withdraw(amount);
    }
    double fromCredit = amount - balance;
    balance = 0;
    usedCredit += fromCredit;
    std::cout << "Withdrawn " << amount << " (from credit: " << fromCredit << ")\n";
    return true;
}

void CreditAccount::describe() const {
    Account::describe();
    std::cout << "  [Credit] Limit: " << creditLimit << " , used: " << usedCredit << "\n";
}
