#include "Run.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/*Run::Run(){
    cout<<"\n  *****************************************************FingerTips Bank**************************************************************";
    while(login_register !=1 || login_register !=2){
        cout<<"\n1 : REGISTER \n2 : LOGIN \n3 : Exit \nYour Choice  : ";
        cin>>login_register;
        if(login_register ==1 ){
            customer = Register();
            user = &customer;
            createAccounts();
            //add.addAccount(saving,current,user);
            loging_in();
            break;
        }else if(login_register==2){
            loging_in();
            break;
        }else if(login_register == 3){
            exit(0);
        }else{
            cout<<"Enter a number in options...";
            continue;
        }
    }
    }
void Run::Menu(){
    cout<<"\n*******************************************************FingerTips Bank*********************************************************\n";
    cout<<"0 : Logout \n1 : Saving Account \n2 : Current Account \n3 : Virtual Card \n4 : Update Details \n5 : Remove Account"<<endl;
    cout<<"Your Choice : ";
    int choice;
    double amount;
    cin>>choice;
    string name= user->getName();
    string tittle = user->getTittle();
    string surname = user->getSurname();
    long int sav_acc = user->getSaving_account_no();
    string sav_acc_no = to_string(sav_acc);
    string cur_acc_no = to_string(user->getCurrent_account_no());
    if(choice==0){
        loging_in();
    }else if(choice == 1){
        saving_account_properties();
    }else if(choice == 2){
        current_account_properties();
    }else if(choice == 3){
        VirtualCard(tittle,name,surname,sav_acc);
        cout<<"1 : Back"<<endl;
        cin>>choice;
        if(choice== 1)
            Menu();
    }
    else if(choice == 4){
        cout<<"You are about to make changes in your account personal details,\n to continue press 1, to return to main menu press 0"<<endl;
        cout<<"Your choice  : ";
        cin>>choice;
        if(choice == 1){
            add.removeAccount(infile,"account.txt",name,surname,sav_acc_no,cur_acc_no);
            customer = user->updateDetails();
            user = &customer;
            add.addAccount(saving,current,user);
            cout<<"Your FingerTips personal details have been updated...."<<endl;
        }else{Menu();}
    }else if(choice == 5){
        cout<<"\nYou are about to Remove your FingerTips Account, All your data and personl details will be deleted from our system"<<endl;
        cout<<"your will not be able to make transactions using FingerTips Bank's saving and current accounts anymore "<<endl;
        cout<<"to continue press 1, to return to main menu press 0"<<endl;
        cout<<"Your choice : ";
        cin>> choice;
        if(choice == 1){
            add.removeAccount(infile,"account.txt",name,surname,sav_acc_no,cur_acc_no);
            cout<<"\nYour FingerTips Account has been succesful removed \n"<<endl;
            exit(0);
        }else{Menu();}
    }
}
void Run::loging_in(){
        cout<<"\n*******************************************************FingerTips Bank**********************************************************\n";
        cout<<"*************************************************************Login********************************************************";
        string username, password;
        cout<< "\nEnter the username  : ";
        cin>>username;
        cout<< "Enter the Password  : ";
        cin>>password;
        customer = existing_Account(username,password);
        user = &customer;
        Login l(user);
        login = l;
        bool isLogin = l.verifyLogin(username,password);
        if(isLogin){
            Menu();
    }else{
        cout<<l.errorLogin()<<endl;
        Run();
    }
}
Customer Run::Register(){
        cout<<"\n******************************************************FingerTips Bank********************************************************\n";
        cout<<"******************************************************Personal Detals***********************************************************";
        string name, surname, Tittle,id, cellphone,username,password,address,gender,confirmPassword;
        cout<<"\n Enter a Tittle         :  ";
        cin>>Tittle;

        cout<<" Enter a Name           :  ";
        cin>>name;

        cout<<" Enter a Surname        :  ";
        cin>>surname;

        cout<<" Select Gender          :  ";
        cin>>gender;

        cout<<" Enter ID               :  ";
        cin>>id;
        cin.ignore();
        cout<<" Enter Physical address :  ";
        getline(cin,address);

        cout<<" Enter the Cellphone    :  ";
        cin>>cellphone;

        cout<<" Enter Username/Email   :";
        cin>>username;

        cout<<" Select a Password      :  ";
        cin>>password;

        cout<<" Confirm Password       :  ";
        cin>>confirmPassword;

        while(!confirmPass(password, confirmPassword)){
            cout<<"\nIncorrect Password!!!"<<endl;
            cout<<"Select a Password   : ";
            cin>>password;

            cout<<" Confirm Password   :  ";
            cin>>confirmPassword;
        }

        Customer new_user(Tittle,name,surname,id,cellphone,username,password,address,gender);
        cout<<"\nPersonal details Verified!!! \n"<<endl;
       return new_user;
}
bool Run::confirmPass(string password,string confirmPassword){
    if(password == confirmPassword){
        return true;
    }else{
        return false;
}    }
Customer Run::existing_Account(string username , string password){
    ifstream infile;
    Customer c(infile,username,password);
    return c;
}
savingAcc Run::create_init_saving_account(){
    double balance=0;
    cout<<"Enter the Saving Account initial deposit amount  : ";
    cin>> balance;
    savingAcc sav(balance);
    return sav;
}
currentAcc Run::create_init_current_account(){
    double balance=0;
    cout<<"Enter the Saving Account initial deposit amount  : ";
    cin>> balance;
    currentAcc cur(balance);
    return cur;
}
void Run::createAccounts(){
    cout<<"\n******************************************************FingerTips Bank********************************************************\n";
    cout<<"*******************************************************Create Account**********************************************************\n";
    int choice;
    double sav_balance=0,cur_balance=0;
    bool checkedIn = false;
    while(!checkedIn){
        cout<<"\n1 Saving Account"<<endl;
        cout<<"2 Current Account"<<endl;
        cout<<"3 Both 1 and 2"<<endl;
        cout<<"Your choice  : ";
        cin>>choice;
        double balance=0;
        if(choice ==1 ){
            currentAcc cur(balance);
            current = &cur;
            sav = create_init_saving_account();
            saving = &sav;
            checkedIn= true;
        }else if(choice ==2){
            savingAcc sav(balance);
            saving = &sav;
            cur = create_init_current_account();
            current= &cur;
            checkedIn= true;
        }else if(choice ==3){
            sav = create_init_saving_account();
            cur = create_init_current_account();
            current= &cur;
            saving = &sav;
            checkedIn= true;
        }else{
            cout<<"\n The choice is not in options";
        }
    }
    cout<<"\n Your FingerTips Bank Account has been successfully created "<<endl;
    cout<<"\n Congratulations, We welcome your to FingerTips Family\n"<<endl;
    cout<<"\n Login to Menu......\n"<<endl;
}
void Run::saving_account_properties(){
    savingAcc sav(user);
    saving = &sav;
    cout<<"\n******************************************************FingerTips Bank********************************************************\n";
    cout<<"*******************************************************Saving Account************************************************************\n";
    cout<<"0 : Back \n1 : Balance \n2 : Deposit \n3 : Make Payment \n4 : Transfere \n5 : Buy Prepaid \n6 : Bank Statement \n7 : Update Limit"<<endl;
    cout<<"Your Choice : ";
    int choice;
    double amount;
    cin>>choice;
    if(choice == 0){
            Menu();
    }else if(choice==1){
        cout<<"Balance : "<<saving->getBalance()<<endl;
    }else if(choice==2){
        cout<<"Enter amount to deposit : ";
        cin>>amount;
        saving->deposit(amount);
    }else if(choice ==3){
        account acc;
        //cout<<"An account number to make payment to : ";
        //cin>>acc;
        cout<<"Amount : ";
        cin>>amount;
        //saving->makePayment(acc,amount);
    }else if(choice == 4){
        cout<<"Enter the amount : ";
        cin>>amount;
        saving->transfere(current,amount);
    }
    else if(choice == 5){
        Prepaid p(saving);
        cout<<"0 : Back \n1 : Voucher \n2 : Data \n3 : Electricity"<<endl;
        cout<<"Your Choice : ";
        cin>>choice;
        if(choice == 1){
            cout<<"Enter amount : ";
            cin>>amount;
            p.buyVoucher(amount);
        }else if(choice == 2){
            cout<<"Enter amount : ";
            cin>>amount;
            p.buyData(amount);}
        else if(choice == 3){
            cout<<"Enter amount : ";
            cin>>amount;
            p.buyElectricity(amount);
        }else{}

    }else if(choice == 6){
        saving->bank_statement();
    }
    cout<<"\n0 : Back \n1 : Exit\n";
    cout<<"Your Choice : ";
    cin>>choice;
    if(choice == 0){
        saving_account_properties();
    }else{
        exit(0);}
}
void Run::current_account_properties(){
    currentAcc cur(user);
    current = &cur;
    cout<<"\n********************************************************FingerTips Bank***********************************************************\n";
    cout<<"*********************************************************Current Account*************************************************************\n";
    cout<<"0 : Back \n1 : Balance \n2 : Deposit \n3 : Make Payment \n4 : Transfere \n5 : Buy Prepaid \n6 : Bank Statement \n7 : Update Limit"<<endl;
    cout<<"Your Choice : ";
    int choice;
    double amount;
    cin>>choice;
    if(choice == 0){
            Menu();
    }else if(choice==1){
        cout<<"Balance : "<<current->getBalance()<<endl;
    }else if(choice==2){
        cout<<"Enter amount to deposit : ";
        cin>>amount;
        current->deposit(amount);
    }else if(choice ==4){
        account acc;
        cout<<"Amount : ";
        cin>>amount;
    }else if(choice == 4){
        cout<<"Enter the amount : ";
        cin>>amount;
        current->transfere(saving,amount);
    }
    else if(choice == 5){
        Prepaid p(current);
        cout<<"0 : Back \n1 : Voucher \n2 : Data \n3 : Electricity"<<endl;
        cout<<"Your Choice : ";
        cin>>choice;
        if(choice == 1){
            cout<<"Enter amount : ";
            cin>>amount;
            p.buyVoucher(amount);
        }else if(choice == 2){
            cout<<"Enter amount : ";
            cin>>amount;
            p.buyData(amount);}
        else if(choice == 3){
            cout<<"Enter amount : ";
            cin>>amount;
            p.buyElectricity(amount);
        }else{}

    }else if(choice == 6){
        current->bank_statement();
    }
    cout<<"\n0 : Back \n1 : Exit\n";
    cout<<"Your Choice : ";
    cin>>choice;
    if(choice == 0){
        saving_account_properties();
    }else{
        exit(0);}

}
void Run::VirtualCard(string tittle,string name,string surname,long int acc){
     cout<<"\n********************************************************FingerTips Bank***********************************************************\n";
    cout<<"*********************************************************Virtual Card*************************************************************\n";
    Virtual_card v;
    virtualcard = v;
    this->virtualcard.tittle = tittle;
    this->virtualcard.name = name;
    this->virtualcard.surname = surname;
    this->virtualcard.account_no = acc;
    this->virtualcard.display();
}

*/
