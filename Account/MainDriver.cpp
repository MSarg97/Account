#include <iostream>
#include <iomanip>
#include <typeinfo> 
#include <vector>

#include "SavingsAccount.h"
#include "CheckingAccount.h"

using namespace std;

int main()
{
    //create two Account objects
    Account account1(10000);
    Account account2(-16); //initializing with invalid balance value

    //set floating-point output formatting
    cout << fixed << setprecision(2);

    cout << "Initial balance of the first account: " << account1.getBalance();
    cout << "\nInitial balance of the second account: " << account2.getBalance();

    //adding amounts to the initial balances of the accounts
    account1.credit(2000);
    account2.credit(1400);

    cout << "\n\nCurrent balance of the first account: " << account1.getBalance();
    cout << "\nCurrent balance of the second account: " << account2.getBalance();

    //withdrawing amounts from the accounts
    account1.debit(5000);
    account2.debit(100000); //trying to withdraw an invalid amount

    cout << "\nCurrent balance of the first account after withdrawal: " << account1.getBalance();
    cout << "\nCurrent balance of the second account after withdrawal: " << account2.getBalance();


    //create SavingsAccount object
    SavingsAccount sAccount(123, 0.605);
    
    cout << "\n\n\nInitial balance of the savings account: " << sAccount.getBalance();
    
    //print the amount of interest
    cout << "\nThe amount of interest earned by the savings account: " << sAccount.calculateInterest();

    //add amount to savings account 
    sAccount.credit(2000);

    cout << "\nCurrent balance of the savings account: " << sAccount.getBalance();

    //print the amount of interest
    cout << "\nThe amount of interest earned by the savings account: " << sAccount.calculateInterest();

    //withdrawing an amount from the savings account 
    sAccount.debit(50);
    
    cout << "\nCurrent balance of the savings account after withdrawal: " << sAccount.getBalance();
    cout << endl;


    //create CheckingAccount object
    CheckingAccount chAccount(1000.25, 50);

    cout << "\n\nInitial balance of the checking account: " << chAccount.getBalance();

    //add an amount to checking account
    chAccount.credit(1500);

    cout << "\nCurrent balance of the checking account: " << chAccount.getBalance();

    //withdrawing an amount from the checking account
    chAccount.debit(500);

    cout << "\nCurrent balance of the checking account after withdrawal: " << chAccount.getBalance();

    //trying to withdraw an invalid amount from the checking account
    chAccount.debit(500000);

    cout << "Current balance of the checking account after withdrawal: " << chAccount.getBalance();
    cout << endl;

    //create vector of Account base-class pointers
    vector<Account*> accounts(2);
  
    //initializing vector with SavingsAccount and CheckingAccount accounts
    accounts[0] = &sAccount;
    accounts[1] = &chAccount;

    //polymorphically process each element in vector accounts
    for (int i = 0; i < accounts.size(); i++)
    {
        //downcast pointer
        SavingsAccount* ptr = dynamic_cast<SavingsAccount*>(accounts[i]);

        cout << "\n\nCurrent balance of " << typeid(*accounts[i]).name() << ": " << accounts[i]->getBalance();

        //withdrawing an amount from the current account
        accounts[i]->debit(250);

        cout << "\nCurrent balance of " << typeid(*accounts[i]).name() << " after withdrawal: " << accounts[i]->getBalance();

        //if the current account is a SavingsAccount, add account's interest value to its current balance
        if (ptr != 0)
            ptr->credit(ptr->calculateInterest());
        
        //get the name of current account and print its current balance
        cout << "\nCurrent balance of " << typeid(*accounts[i]).name() << " after adding an amount: " << accounts[i]->getBalance();    
    }
    cout << endl;

    return 0;
}
