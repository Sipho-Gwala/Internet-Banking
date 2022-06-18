#ifndef LOGIN_H
#define LOGIN_H
#include "Customer.h"

class Login
{
    public:
        Login();
        Login(Customer *c);
    bool verifyLogin(string userName, string password);
    string errorLogin();
    void logout();

    private:
        Customer *customer;
};

#endif // LOGIN_H
