#include "savingAcc.h"
#include "currentAcc.h"
#include "account.h"
#include "Customer.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

savingAcc::savingAcc(Customer *c){
    this-> customer = c;
    this->balance = c->getSaving_acc_balance();
    this-> accountNo = c->getSaving_account_no();
}
savingAcc::savingAcc(){}

savingAcc::savingAcc(double initialDeposit){
        this->balance = initialDeposit;
    }
double savingAcc::getBalance(){
    return balance;
}
long savingAcc::getAccountNo(){
    return accountNo;
}
double savingAcc::getLimit(){
    return limit;
}
void savingAcc::setLimit(double amount){
    limit =amount;
}
string savingAcc::getAccountType(){
    return "Savings Account";
}
void savingAcc::deposit(double amount){
    balance+=amount;
    customer->setSaving_acc_balance(balance);
}
void savingAcc::transfere(double amount){
    if(verifySufficientFunds(amount)){
        balance-= amount;
        customer->setSaving_acc_balance(balance);
        customer->setCurrent_acc_balance(customer->getCurrent_acc_balance()+amount);
        string details = "FingerTips : Transfer -R";
        details.append(to_string(amount));
        details.append(" from current account, available balance R");
        details.append(to_string(balance));
        transaction(details);
    }

}
void savingAcc::makePayment(account *acc, double amount){
    if(amount>getLimit()){
        cout<<"You have Exceeded limit "<<endl;
    }
    if(verifySufficientFunds(amount)){
        balance -= amount;
        currentAcc c;
        this->customer->setSaving_acc_balance(balance);
        acc->recievedPayment(amount);
        string details = "FingerTips : Payment -R";
        details.append(to_string(amount));
        details.append(" from saving account, available balance R");
        details.append(to_string(balance));
        transaction(details);
        cout<<"You have successfully made payment to "<<to_string(acc->getAccountNo())<<" account "<<endl;
        system("pause");
        }
}
bool savingAcc::verifySufficientFunds(double amount){
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
void savingAcc::bank_statement(){
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
void savingAcc::transaction(string details){
    fstream files;
    files.open("files.txt",ios::app);
        if(files.is_open()){
            files<<details<<endl;
        }
        files.close();
}
void savingAcc::recievedPayment(double amount){
    this->customer->setSaving_acc_balance(customer->getSaving_acc_balance()+deductedPayment(amount));
    string details = "FingerTips : Received Payment +R";
    details.append(to_string(amount));
    details.append(" from saving account, available balance R");
    details.append(to_string(balance));
    transaction(details);
}
double savingAcc::deductedPayment(double amount){
    return amount = amount - (amount*0.005);
}
