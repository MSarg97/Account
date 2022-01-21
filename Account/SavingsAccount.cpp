#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(double amount, double interest): Account(amount)
{
	//assign the interest to interestRate data member
	interestRate = interest;
}

double SavingsAccount::calculateInterest()
{
	//counting the interest value by multiplying the interest rate and the current balance of the account
	return balance * interestRate;
}
