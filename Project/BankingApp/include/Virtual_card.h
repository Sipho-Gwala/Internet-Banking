#ifndef VIRTUAL_CARD_H
#define VIRTUAL_CARD_H
#include <iostream>
#include <string>

using namespace std;

struct Virtual_card
{
    string expire_date = "23/06/2025";
    int cvv;
    static int create_cvv;
    long account_no ;
public:
    Virtual_card();
    void display();
    string tittle, name, surname;
};

#endif // VIRTUAL_CARD_H
