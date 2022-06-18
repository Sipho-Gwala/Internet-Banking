#ifndef CURRENTACC_H
#define CURRENTACC_H
#include "savingAcc.h"
#include "account.h"
#include "Customer.h"

class currentAcc : public account{
private:
    //Customer *customer;
    string account_type;
    long accountNo;
    double balance;
    float interest_rate;
    double limit=15000;
public:
    Customer* customer;
    currentAcc();
    currentAcc(Customer *c);
    currentAcc(double initialDeposit);
    double getBalance();
    void setLimit(double amount);
    double getLimit();
    long getAccountNo();
    string getAccountType();
    void deposit(double amount);
    void transfere(double amount);
    void makePayment(account *acc , double amount);
    bool verifySufficientFunds(double amount);
    void bank_statement();
    void transaction(string details);
    void recievedPayment(double amount);
    double deductedPayment(double amount);

};




#endif // CURRENTACC_H
