#include "currentAcc.h"
#include "savingAcc.h"
#include "account.h"
#include "Customer.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

currentAcc::currentAcc(Customer *c){
    customer = c;
    this->balance = c->getCurrent_acc_balance();
    this->accountNo = c->getCurrent_account_no();
}
currentAcc::currentAcc(){}
currentAcc::currentAcc(double initialDeposit){
    this->balance = initialDeposit;
}
double currentAcc::getBalance(){
    return balance;
}
long currentAcc::getAccountNo(){
    return accountNo;
}
string currentAcc::getAccountType(){
    return "Current Account";
}
void currentAcc::deposit(double amount){
    balance+=amount;
    customer->setCurrent_acc_balance(balance);
}
double currentAcc::getLimit(){
    return limit;
}
void currentAcc::setLimit(double amount){
    limit =amount;
}
void currentAcc::transfere(double amount){
    if(verifySufficientFunds(amount)){
        balance-= amount;
        customer->setCurrent_acc_balance(balance);
        customer->setSaving_acc_balance(customer->getSaving_acc_balance()+amount);
        string details = "FingerTips : Transfer -R";
        details.append(to_string(amount));
        details.append(" into saving account, available balance R");
        details.append(to_string(balance));
        transaction(details);
    }
}
void currentAcc::makePayment(account *acc , double amount){
    if(amount>getLimit()){
        cout<<"You have Exceeded limit "<<endl;
    }
    if(verifySufficientFunds(amount)){
        balance -= amount;
        this->customer->setCurrent_acc_balance(balance);
        acc->recievedPayment(amount);
        string details = "FingerTips : Payment -R";
        details.append(to_string(amount));
        details.append(" from current account, available balance R");
        details.append(to_string(balance));
        transaction(details);
        cout<<"You have successfully made payment to "<<to_string(acc->getAccountNo())<<" account "<<endl;
        system("pause");
    }
}
bool currentAcc::verifySufficientFunds(double amount){
    if((balance - amount) >= 0){
        return true;
    }else{
        cout<<"Insufficient funds, To make this transaction"<<endl;
        system("Color 94");
        system("pause");
        system("Color 79");
        return false;
    }
}
void currentAcc::bank_statement(){
    fstream file;
    file.open("files.txt",ios::in);
    if(file.is_open()){
        string name;
        while(getline(file,name)){
            cout<<name<<endl;
        }
        file.close();
    }
}
void currentAcc::transaction(string details){
    fstream files;
    files.open("transactions.txt",ios::app);
        if(files.is_open()){
            files<<details<<endl;
        }
        files.close();
}
void currentAcc::recievedPayment(double amount){
    this->customer->setCurrent_acc_balance(customer->getCurrent_acc_balance()+deductedPayment(amount));
    string details = "FingerTips : Recived Payment +R";
    details.append(to_string(amount));
    details.append(" from saving account, available balance R");
    details.append(to_string(balance));
    transaction(details);
}
double currentAcc::deductedPayment(double amount){
    return amount = amount - (amount*0.005);
}


