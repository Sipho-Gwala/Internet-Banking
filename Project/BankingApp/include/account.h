#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
class account
{
    private:

    ifstream transaction_input;
    ifstream transaction_output;

public:
    account();
    account(string customerID ,string accountType , string userName , string password);
    virtual void transaction();
    virtual double getBalance();
    virtual long getAccountNo();
    virtual string getAccountType();
    virtual void setLimit(double amount);
    virtual double getLimit();
    virtual void bank_statement();
    virtual void deposit(double amount);
    virtual void transfere(account *sav ,double amount);
    virtual void makePayment(account *acc , double amount);
    virtual bool verifySufficientFunds(double amount);
    virtual void recievedPayment(double amount);
    virtual double deductedPayment(double amount);
};

#endif // ACCOUNT_H
