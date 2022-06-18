#include "account.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

account::account(){}
void account::transaction(){}
long account::getAccountNo(){}
double account::getBalance(){}
void account::bank_statement(){}
string account::getAccountType(){}
void account::deposit(double amount){}
void account::transfere(account *sav, double amount){}
void account::makePayment(account *acc , double amount){}
bool account::verifySufficientFunds(double amount){return true;}
void account::recievedPayment(double amount){}
double account::deductedPayment(double amount){}
void account::setLimit(double amount){}
double account::getLimit(){}

