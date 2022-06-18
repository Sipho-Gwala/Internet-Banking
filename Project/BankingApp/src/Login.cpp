#include "Login.h"
#include "Customer.h"
#include <string>
#include <iostream>

using namespace std;

Login::Login(){}
Login::Login(Customer *c)
{
   this->customer = c; // copy constructor
}
void Login::logout()
{
    exit(3);
}
bool Login::verifyLogin(string userName, string password){
    if(this->customer->getUserName() == userName && this->customer->getPassword() == password){
        return true;
    }else{
        errorLogin();
        return false;
    }
}
string Login::errorLogin(){
    string message = "\nIncorrect Login Details, Try again!!!";
    message.append("\nTo create FingerTips account, Press 1 ");
    return message;
}
