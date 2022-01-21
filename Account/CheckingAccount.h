#ifndef CHECKINGACOOUNT_H
#define CHECKINGACCOUNT_H

#include "Account.h"

class CheckingAccount : public Account
{
public:
	CheckingAccount(double, double);
	void credit(double); //add an amount
	bool debit(double); //withdraw an amount
private:
	double fee; //fee is substracted from the current account balance after successful transaction
}; //end of the CheckingAccount class

#endif // !CHECKINGACOOUNT_H
