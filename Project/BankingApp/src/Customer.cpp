#include "Customer.h"
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Customer::Customer(){}
Customer::Customer( long saving_account_no,double saving_acc_balance,long current_account_no, double current_acc_balance,
                   string tittle,string name,string surname, string username, string password,
                    string id,string address,string gender, string cellphone)
{
    this-> tittle = tittle;
    this-> name = name;
    this-> surname = surname;
    this-> id = id;
    this-> cellphone = cellphone;
    this-> username = username;
    this-> password = password;
    this-> address = address;
    this-> gender = gender;
    this->saving_account_no = saving_account_no;
    this->current_account_no = current_account_no;
    this->saving_acc_balance = saving_acc_balance;
    this->current_acc_balance = current_acc_balance;
}

string Customer::getTittle(){return tittle;}
string Customer::getName(){return name;}
string Customer::getSurname(){return surname;}
string Customer::getUserName(){return username;}
string Customer::getId(){return id;}
string Customer::getPassword(){return password;}
string Customer::getCellphone(){return cellphone;}
string Customer::getGender(){return gender;}
string Customer::getAddress(){return address;}
long Customer:: getSaving_account_no(){return saving_account_no;}
long Customer:: getCurrent_account_no(){return  current_account_no;}
double Customer:: getSaving_acc_balance(){return saving_acc_balance;}
double Customer:: getCurrent_acc_balance(){return current_acc_balance;}


void Customer::setName(string name){this->name = name;}
void Customer:: setUserName(string name){this->username = name;}
void Customer:: setPassword(string name){this->password = name;}
void Customer:: setSurname(string name){{this->surname = name;}}
void Customer:: setId(string name){this->id = name;}
void Customer:: setGender(string name){this->gender = name;}
void Customer:: setTittle(string name){this->tittle = name;}
void Customer:: setCellphone(string name){this->cellphone = name;}
void Customer:: setAddress(string name){this->address = name;}
void Customer:: setSaving_acc_balance(double amount){this->saving_acc_balance = amount;}
void Customer:: setCurrent_acc_balance(double amount){this->current_acc_balance = amount;}
