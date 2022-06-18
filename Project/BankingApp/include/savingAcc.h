#ifndef SAVINGACC_H
#define SAVINGACC_H
#include "account.h"
#include "currentAcc.h"
#include <vector>
class Customer;

class savingAcc : public account
{
private:
    //vector<int> statement;
    string account_type;
    long accountNo;
    double balance;
    float interest_rate;
    double limit =5000;
public:
      Customer* customer;
    savingAcc();
    savingAcc(Customer *c);
    savingAcc(double initialDeposit);
    string getAccountType();
    double getBalance();
    void setLimit(double amount);
    double getLimit();
    long getAccountNo();
    void deposit(double amount);
    void transfere(double amount);
    void makePayment(account *acc, double amount);
    bool verifySufficientFunds(double amount);
    void bank_statement();
    void transaction(string details);
    void recievedPayment(double amount);
    double deductedPayment(double amount);
};

#endif // SAVINGACC_H
