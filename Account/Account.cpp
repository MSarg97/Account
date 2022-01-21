#include <iostream>
#include "../AccountUnitTest/pch.h"
#include "Account.h"

Account::Account(double amount)
{
	//if the amount is negative, assign to it 0 and print an error message, else assign it to balance
	if (amount < 0.0)
	{ 
		balance = 0.0;
		std::cout << "Initial balance is invalid, 0.0 is assigned to the balance!\n\n";
	}
	else
		balance = amount;
}

void Account::credit(double amount)
{
	//add an amount to account's current balance
	balance += amount;
}

bool Account::debit(double amount)
{
	//if the amount is bigger, than the current balance, print an error message, else withdraw it 
	if (amount > balance)
	{
		std::cout << "\n\nDebit amount exceeds account's current balance!\n";
		return false;
	}
	else
		balance -= amount;
	return true;
}

double Account::getBalance()
{
	//return the current balance
	return balance;
}
