#include <iostream>
#include <string>
#include <fstream>

#include "currentAcc.h"
#include "savingAcc.h"
#include "account.h"
#include "Prepaid.h"
#include "Customer.h"
#include "Bank.h"
#include "Virtual_card.h"


using namespace std;

int main()
{
    system("Color 79");
    Bank bank;
    bank.filewrite();
    /*Customer c(401,5000.00,501,7858.00,"Mr","Sipho","Gwala","sipho@12","mkmk","00404949944949","south","Male","049499494");
    Customer cb(401,5000.00,501,7858,"Mr","Sipho","Gwala","sipho@12","mkmk","099940400440","South","Male","84848448");
    c.addCustomer(&cb);*/
    return 0;
}
