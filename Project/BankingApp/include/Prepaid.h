#ifndef PREPAID_H
#define PREPAID_H
#include "account.h"


class Prepaid
{
    public:
        Prepaid(account *acc);
        void buyAirtime(int amount);
        void buyVoucher(int amount);
        void buyData(int amount);
        void buyElectricity(int amount);
       string displayMessage(string details);


    private:
       account *acc;
};

#endif // PREPAID_H
