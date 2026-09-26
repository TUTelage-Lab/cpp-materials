#include "Loan.h"

Loan::Loan(const std::string &owner,
           double debt,
           double interestRate) : owner(owner),
                                  debt(debt),
                                  interestRate(interestRate) {
}
