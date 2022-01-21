#ifndef SAVINGSACCOUNTS_H
#define SAVINGSACCOUNTS_H

#include "Account.h"

class SavingsAccount : public Account
{
public:
	SavingsAccount(double, double);
	double calculateInterest(); //function for counting the interest rate
private:
	double interestRate; //interest rate for the current balance
}; //end of the SavingsAccount class

#endif // !SAVINGSACCOUNTS_H
