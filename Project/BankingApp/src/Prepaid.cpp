#include "Prepaid.h"
#include "account.h"
#include <iostream>
#include <string>

using namespace std;

Prepaid::Prepaid(account *acc)
{
    this-> acc = acc;
}

void Prepaid::buyAirtime(int amount){
    if (acc->verifySufficientFunds(amount)){
        acc->deductedPayment(amount);
        string details = "FingerTips";// : airtime purchased -R";
        details.append(""+amount);
        cout<<"Your R"<<amount<<" airtime purchase was successful"<<endl;
    }
}
void Prepaid::buyVoucher(int amount){
    if (acc->verifySufficientFunds(amount)){
        acc->deductedPayment(amount);
        string details = "FingerTips : voucher purchased -R";
        details += amount;
        cout<<"Your R"<<amount<<" voucher purchase was successful"<<endl;
    }
}
void Prepaid ::buyData(int amount){
    if (acc->verifySufficientFunds(amount)){
        acc->deductedPayment(amount);
        string details = "FingerTips : data purchased -R";
        details += amount;
        cout<<"Your R"<<amount<<" data purchase was successful"<<endl;
    }
}
void Prepaid::buyElectricity(int amount){
    if (acc->verifySufficientFunds(amount)){
        acc->deductedPayment(amount);
        string details = "FingerTips : electricity purchased -R";
        details += amount;
        cout<<"Your R"<<amount<<" electricity purchase was successful"<<endl;
    }
}
