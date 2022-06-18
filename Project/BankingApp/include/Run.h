#ifndef RUN_H
#define RUN_H


#include <iostream>
#include <string>
#include <fstream>
#include "Virtual_card.h"
#include "currentAcc.h"
#include "savingAcc.h"
#include "account.h"
#include "Prepaid.h"
#include "Customer.h"
#include "Login.h"
#include "Bank.h"

using namespace std;

class Run{
    int login_register;
    account *saving = nullptr, *current=nullptr;
    savingAcc sav;currentAcc cur;
    Customer *user=nullptr;
    Customer customer;
    Bank add;
    Login login;
    Virtual_card virtualcard;
    ifstream infile;
public :
    Run();
private:
    void loging_in();
    Customer Register();
    void saving_account_properties();
    void current_account_properties();
    Customer existing_Account(string username , string password);
    savingAcc create_init_saving_account();
    currentAcc create_init_current_account();
    void Menu();
    bool  confirmPass(string password,string confirmPassword);
    void createAccounts();
    void removeAccount();
    void VirtualCard(string tittle,string name,string surname,long int acc);
};

#endif // RUN_H
