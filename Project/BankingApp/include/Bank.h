#ifndef BANK_H
#define BANK_H
#include "account.h"
#include "currentAcc.h"
#include "savingAcc.h"
#include "Customer.h"
#include "Prepaid.h"
#include "Virtual_card.h"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>

class Bank
{
    public:
        Bank();
        void administrator();
        void terminate();
        void Register();
        bool confirmPass(string password,string confirmPassword);
        void addCustomer(Customer *add);
        savingAcc create_init_saving_account();
        currentAcc create_init_current_account();
        void createAccounts();
        void display();
        void loging_in();
        bool search_user(string username,string password);
        void filewrite();
        vector<Customer *> database;
        void populate();
        void Menu();
        void removeAccount(Customer *customer);
        double sav_glob, cur_glob;
        void VirtualCard(string tittle,string name,string surname,long int acc);
    private:
        string name = "FingerTips", administrator_userName = "fingertips@ourbank";
        string code = "3557";
        savingAcc *saving;
        currentAcc *current;
        Customer *curCust;
        int index;
        long int sav_account_no_generator,cur_account_no_generator;
};

#endif // BANK_H
