#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "currentAcc.h"
#include "savingAcc.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Customer
{
    public:
        Customer();
        Customer( long saving_account_no,double saving_acc_balance,long current_account_no, double current_acc_balance,
                   string tittle,string name,string surname, string username, string password,
                    string id,string address,string gender, string cellphone);
        void update_login_details();
        string getName();
        string getUserName();
        string getPassword();
        string getSurname();
        string getId();
        string getGender();
        string getTittle();
        string getCellphone();
        string getAddress();
        long getSaving_account_no();
        long getCurrent_account_no();
        double getSaving_acc_balance();
        double getCurrent_acc_balance();
        void setName(string name);
        void setUserName(string name);
        void setPassword(string name);
        void setSurname(string name);
        void setId(string name);
        void setGender(string name);
        void setTittle(string name);
        void setCellphone(string name);
        void setAddress(string name);
        void setSaving_acc_balance(double amount);
        void setCurrent_acc_balance(double amount);


    private:
        string name;
        string surname;
        string tittle;
        string id;
        string cellphone;
        string username;
        string password;
        string address;
        string gender;
        long saving_account_no;
        long current_account_no;
        double saving_acc_balance;
        double current_acc_balance;
        ifstream customer_login_details_input;
        ofstream customer_login_details_output;
};

#endif // CUSTOMER_H
