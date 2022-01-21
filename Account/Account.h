#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
public:
	Account(double);
	virtual void credit(double); //add an amount
	virtual bool debit(double); //withdraw an amount
	double getBalance(); //return the current balance
protected:
	double balance; //balance of the current account
}; //end of the Account class

#endif // !ACCOUNT_H