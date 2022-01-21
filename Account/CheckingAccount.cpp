#include "CheckingAccount.h"
 
CheckingAccount::CheckingAccount(double amount, double fe) : Account(amount)
{
	//assign fe to fee data member
	fee = fe;
}

void CheckingAccount::credit(double amount)
{
	//substract the fee after successfully adding an amount
	balance += amount - fee;
}

bool CheckingAccount::debit(double amount)
{  
	//if an amount is withdrawn successfully, substract the fee from the current balance 
	if (Account::debit(amount))
		balance -= fee;
	return true;
}
