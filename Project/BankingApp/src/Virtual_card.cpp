#include "Virtual_card.h"

Virtual_card::Virtual_card()
{
    this->cvv = create_cvv+1;
}
int Virtual_card:: create_cvv = 100;
void Virtual_card::display(){
    cout<<"\n"<<endl;
    cout<<"           **********************************************************"<<endl;
    cout<<"           *                    VIRTUAL CARD                        *"<<endl;
    cout<<"           *   Tittle                    : "<< this->tittle<<"      *" <<endl;
    cout<<"           *   Name                      : " <<this->name  <<"      *"<<endl;
    cout<<"           *   Surname                   : " <<this->surname<<"     *"<<endl;
    cout<<"           *   Account no                : " <<this->account_no<<"  *"<<endl;
    cout<<"           *   CVV                       : " <<this->cvv<<"         *"<<endl;
    cout<<"           *   Expire Date(dd/mm/yy)     : " <<this->expire_date<<" *"<<endl;
    cout<<"           **********************************************************"<<endl;
}
