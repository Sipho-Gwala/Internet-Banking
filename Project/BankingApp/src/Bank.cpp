#include "Bank.h"
#include <typeinfo>

using namespace std;
 Bank::Bank(){
     system("cls");
    cout<<"\n  *****************************************************FingerTips Bank**************************************************************";
    int option;
    populate();
    while(cin.good() && (option !=1 || option !=2)){
        cout<<"\n0 : EXIT \n1 : REGISTER \n2 : LOGIN \n3 : FINGERTIPS ADMINISTRATOR \nYour Choice  : ";
        cin>>option;
        if(option ==1 ){
            Register();
            loging_in();
            break;
        }else if(option==2){
            loging_in();
            break;
        }else if(option == 0){
            terminate();
        }else if(option ==3){
            administrator();
            break;
        }
        else{
            cout<<"Enter a number in options...";
            continue;
        }
    }
 }

 void Bank::loging_in(){
     system("cls");
    cout<<"\n*******************************************************FingerTips Bank**********************************************************\n";
    cout<<"*************************************************************Login********************************************************";
    string username, password;
    cout<< "\nEnter the username  : ";
    cin>>username;
    cout<< "Enter the Password  : ";
    cin>>password;
    if(search_user(username,password)){
        Menu();
    }else{
        cout<<"\nIncorrect Login Details, Try again!!!";
        cout<<("\nTo create FingerTips account, Press 1 \n")<<endl;
        cout<<endl;
        system("color 94");
        system("pause");
        system("Color 79");
        Bank();
    }
}

void Bank::Register(){
    system("cls");
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

        cout<<" Enter Username/Email   :  ";
        cin>>username;

        cout<<" Select a Password      :  ";
        cin>>password;

        cout<<" Confirm Password       :  ";
        cin>>confirmPassword;

        while(!confirmPass(password, confirmPassword)){
            cout<<"\nIncorrect Password!!!"<<endl;
            cout<<" Select a Password  :  ";
            cin>>password;

            cout<<" Confirm Password   :  ";
            cin>>confirmPassword;
        }
        cout<<"\nPersonal details Verified!!! \n"<<endl;
        createAccounts();
        if(database.size()>0){sav_account_no_generator = database[database.size()-1]->getSaving_account_no()+1;
                            cur_account_no_generator = database[database.size()-1]->getCurrent_account_no()+1;}
        else{sav_account_no_generator=4000,cur_account_no_generator=99000;}

        this->database.push_back(new Customer(sav_account_no_generator,sav_glob,cur_account_no_generator,cur_glob,Tittle,name,surname,
                          username,password,id,address,gender,cellphone));
        system("pause");
}
bool Bank::confirmPass(string password,string confirmPassword){
    if(password == confirmPassword){
        return true;
    }else{
        return false;
}    }

void Bank::addCustomer(Customer *customer){
    this->database.push_back(customer);
}
bool Bank::search_user(string username,string password){
    for(int i=0 ; i< database.size();i++){
        if(username == database[i]->getUserName() && password == database[i]->getPassword()){
            curCust = database[i];
            index = i;
            return true;
            break;
        }
    }
}
void Bank:: filewrite(){
     ofstream ofs;
     ofs.open("account.txt", ofstream::out | ofstream::trunc);
     ofs.close();
    fstream infile("account.txt",ios::app);
    if(infile.is_open()){
        for(int i=0; i<database.size();i++){
            infile<<to_string(database[i]->getSaving_account_no())<<" ";
            infile<<to_string(database[i]->getSaving_acc_balance())<<" ";
            infile<<to_string(database[i]->getCurrent_account_no())<<" ";
            infile<<to_string(database[i]->getCurrent_acc_balance())<<" ";
            infile<<database[i]->getTittle()<<" ";
            infile<<database[i]->getName()<<" ";
            infile<<database[i]->getSurname()<<" ";
            infile<<database[i]->getUserName()<<" ";
            infile<<database[i]->getPassword()<<" ";
            infile<<database[i]->getId()<<" ";
            infile<<database[i]->getAddress()<<" ";
            infile<<database[i]->getGender()<<" ";
            infile<<database[i]->getCellphone()<<" "<<endl;
            }
       infile.close();
    }
}
savingAcc Bank::create_init_saving_account(){
    cout<<"Enter the Saving Account initial deposit amount  : ";
    cin>> sav_glob;
    savingAcc sav(sav_glob);
    return sav;
}
currentAcc Bank::create_init_current_account(){
    cout<<"Enter the Current Account initial deposit amount  : ";
    cin>> cur_glob;
    currentAcc cur(cur_glob);
    return cur;
}
void Bank::createAccounts(){
    cout<<"\n******************************************************FingerTips Bank********************************************************\n";
    cout<<"****************************************************Create Bank Accounts*******************************************************\n";
    int choice;
    bool checkedIn = false;
    while(!checkedIn){
        cout<<"\n1 Saving Account"<<endl;
        cout<<"2 Current Account"<<endl;
        cout<<"3 Both 1 and 2"<<endl;
        cout<<"Your choice  : ";
        cin>>choice;
        if(choice ==1 ){
            currentAcc cur(cur_glob);
            current = &cur;
            savingAcc sav = create_init_saving_account();
            saving = &sav;
            checkedIn= true;
        }else if(choice ==2){
            savingAcc sav(sav_glob);
            saving = &sav;
            currentAcc cur = create_init_current_account();
            current = &cur;
            checkedIn= true;
        }else if(choice ==3){
            savingAcc sav = create_init_saving_account();
            currentAcc cur = create_init_current_account();
            saving = &sav;
            current = &cur;
            checkedIn= true;
        }else{
            cout<<"\n The choice is not in options";
        }
    }
    cout<<"\n Your FingerTips Bank Account has been successfully created "<<endl;
    cout<<"\n Congratulations, We welcome your to FingerTips Family\n"<<endl;
    cout<<"\n Login to Menu......\n"<<endl;
}
void Bank::populate(){
    ifstream infile;
    string word;
    vector<string> line;
    infile.open("account.txt");
    if(infile.is_open()){
        while(infile>>word){
            line.push_back(word);
            if(line.size()== 13){
                this->database.push_back(new Customer(atol(line[0].c_str()),stod(line[1].c_str()),atol(line[2].c_str())
                            ,stod(line[3].c_str()),line[4],line[5],line[6],line[7],line[8],line[9],line[10],line[11],line[12]));
                line.clear();
            }
        }
        infile.close();
    }
}
void Bank::display(){
    cout<<"\nFingerTips Bank Active Customers : \n"<<endl;
    cout << left << setw(8) << "Title" << left << setw(9) << "Name" << left
         << setw(10)<< "Surname" << left << setw(11) << "Username"  << left << setw(12) << "Password" <<left
          << setw(20) << "Identity number" << left << setw(15) << "Cellphone" << left
         << setw(25)<< "Physical Address" << left << setw(10) << "Gender"  << left << setw(10) << "Saving Account" <<
         left << setw(10) << "Balance" << left << setw(10) << "Current Account" << left<< setw(7)<< "Balance" << endl;

    cout<<"      \t\t\t  \t   \t\t\t\t"<<endl;
    for(Customer *ptr: database){
    cout<<left<<setw(8)<<ptr->getTittle()
        <<left<<setw(10)<<ptr->getName()
        << left << setw(10) << ptr->getSurname()
        << left << setw(12) << ptr->getUserName()
        << left << setw(12) << ptr->getPassword()
        << left << setw(20) << ptr->getId()
        << left << setw(15) << ptr->getCellphone()
        << left << setw(25) << ptr->getAddress()
        << left << setw(10) << ptr->getGender()
        << left << setw(10) << ptr->getSaving_account_no()
        << left << setw(10) << ptr->getSaving_acc_balance()
        << left << setw(10) << ptr->getCurrent_account_no()
        << left << setw(7) << ptr->getCurrent_acc_balance()
        << endl;

    }
}
void Bank::Menu(){
    system("cls");
    cout<<"\n*******************************************************FingerTips Bank*********************************************************\n";
    cout<<"0 : Logout \n1 : Enquiry Balances \n2 : Deposit \n3 : Transfer \n4 : Make Payment \n5 : Virtual Card \n6 :  Update Details \n7 : Buy Prepaid \n8 : Update Limits \n9 : Remove Account \n10 : Bank Statement"<<endl;
    cout<<"Your Choice : ";
    int choice;
    savingAcc sav(curCust);
    saving = &sav;
    currentAcc cur(curCust);
    current = &cur;
    double amount;
    cin>>choice;
    if(choice==0){
        terminate();
    }else if(choice == 1){
        cout<<"\nCurrent Account Balance : "<<curCust->getCurrent_acc_balance()<<endl;
        cout<<"Saving Account Balance : "<<curCust->getSaving_acc_balance()<<endl;
        system("pause");
        Menu();

    }else if(choice == 2){
        cout<<"You are about to make a deposit : "<<endl;
        cout<<"1 : Saving Account \n2 : Current Account"<<endl;
        cout<<"Your choice : ";
        cin>>choice;
        if(choice == 1){
            cout<<"Enter the amount : ";
            cin>>amount;
            saving->deposit(amount);
        }else if(choice ==2){
            cout<<"Enter the amount : ";
            cin>>amount;
            current->deposit(amount);
        }else{Menu();}
        cout<<"\nYou have successfully deposited +R"<<amount<<endl;
        system("pause");
        Menu();
    }else if(choice == 3){
        cout<<"1 : To Saving Account \n2 : To Current Account"<<endl;
        cout<<"Your choice : ";
        cin>>choice;
        if(choice == 1){
            cout<<"Enter the amount : ";
            cin>>amount;
            current->transfere(amount);
            cout<<"\nYour transfer was successfully +R"<<amount<<endl;
        }else if(choice==2){
            cout<<"Enter the amount : ";
            cin>>amount;
            saving->transfere(amount);
            cout<<"\nYour transfer was successfully +R"<<amount<<endl;
        }else{Menu();}
        system("pause");
        Menu();

    }
    else if(choice == 4){
        long int account_number;int choice;
        cout<<"\nEnter the Beneficiary account number : ";
        cin>>account_number;
        cout<<"Enter the amount to pay : ";
        cin>>amount;
        bool isNotFound;
        cout<<"\nYou are about to make payment, Make payment with : \n1 : Saving Account \n2 : Current Account \n3 : Cancel"<<endl;
        cout<<"Your choice : ";
        cin>>choice;
        if(choice ==3){Menu();}
        for(int i=0; i<database.size();i++){
            if(database[i]->getSaving_account_no()== account_number){
                isNotFound=true;
                savingAcc sav(database[i]);
                account *temp = &sav;
                if(choice == 1){saving->makePayment(temp,amount);break;}
                else if(choice==2){current->makePayment(temp,amount);break;}
                else{Menu();}
            }else if(database[i]->getCurrent_account_no()== account_number){
                isNotFound=true;
                currentAcc cur(database[i]);
                account *temp = &cur;
                if(choice == 1){saving->makePayment(temp,amount);break;}
                else if(choice==2){current->makePayment(temp,amount);break;}
                else{Menu();}
            }else{
                isNotFound=false;
            }
        }
        if(!isNotFound){
            cout<<"\nAccount "<<account_number<<" does not exist . . ."<<endl;
            system("pause");
        }
        Menu();

    }
    else if(choice == 5){
        VirtualCard(curCust->getTittle(),curCust->getName(),curCust->getSurname(),curCust->getSaving_account_no());
        cout<<"1 : Back"<<endl;
        cin>>choice;
        if(choice== 1)
            Menu();
        }
    else if(choice == 6){
        system("cls");
        cout<<"\n******************************************************FingerTips Bank********************************************************\n";
        cout<<"**************************************************Update Personal Details*****************************************************\n";
        cout<<"\nYou are about to make changes to your account personal details . . ."<<endl;
        cout<<"\nTo change name press 1, to continue, press any number . . . "<<endl;
        cout<<"Your choice : ";
        cin>>choice;
        if(choice == 1){
            cout<<"Enter a new name : ";
            string change;
            cin>>change;
            curCust->setName(change);
        }
        cout<<"\nTo change surname press 1, to continue, press any number . . . "<<endl;
        cout<<"Your choice : ";
        cin>>choice;
        if(choice == 1){
            cout<<"Enter a new surname : ";
            string change;
            cin>>change;
            curCust->setSurname(change);
        }
        cout<<"\nTo change username press 1, to continue, press any number . . . "<<endl;
        cout<<"Your choice : ";
        cin>>choice;
        if(choice == 1){
            cout<<"Enter a new username : ";
            string change;
            cin>>change;
            curCust->setUserName(change);
        }
        cout<<"\nTo change password press 1, to continue, press any number . . . "<<endl;
        cout<<"Your choice : ";
        cin>>choice;
        if(choice == 1){
            cout<<"Enter a new password : "<<endl;
            string change;
            cin>>change;
            curCust->setPassword(change);
        }

        cout<<"\nYour FingerTips personal details have been updated...."<<endl;
        system("pause");
        Menu();
        }else if(choice==8){
            cout<<"\nYou are about to update limit of your accounts\n"<<endl;
            cout<<"Your Current Saving account and Current account limits are : "<<endl;
            cout<<"Saving Account Limit : "<<saving->getLimit()<<"\nCurrent Account Limit : "<<current->getLimit()<<endl;
            cout<<"\n1 : Update Saving Account limit \n2 : Update Current Account limit "<<endl;
            cout<<"Your choice : ";
            cin>>choice;
            if(choice ==1){
                cout<<"Enter the amount : ";
                cin>>amount;
                saving->setLimit(amount);
            }else if(choice ==2){
                cout<<"Enter the amount : ";
                cin>>amount;
                current->setLimit(amount);
            }else{
                Menu();
            }
            cout<<"Your limit have been successfully updated . . ."<<endl;
            system("pause");
            Menu();
        }else if(choice==7){
            system("cls");
            cout<<"\n******************************************************FingerTips Bank********************************************************\n";
            cout<<"*******************************************************Prepaid***********************************************************\n";
            cout<<"0 : Back \n1 : Voucher \n2 : Data \n3 : Airtime \n4 : Electricity"<<endl;
            cout<<"Your Choice : ";
            cin>>choice;
            Prepaid p(saving);
            if(choice == 1){
                cout<<"Enter amount : ";
                cin>>amount;
                p.buyVoucher(amount);
            }else if(choice == 2){
                cout<<"Enter amount : ";
                cin>>amount;
                p.buyData(amount);}
            else if(choice == 4){
                cout<<"Enter amount : ";
                cin>>amount;
                p.buyElectricity(amount);
            }else if(choice = 3){
                cout<<"Enter amount : ";
                cin>>amount;
                p.buyAirtime(amount);
            }
            else{Menu();}
            system("pause");
            Menu();
            }
        else if(choice == 9){
        cout<<"\nYou are about to Remove your FingerTips Account, All your data and personl details will be deleted from our system"<<endl;
        cout<<"your will not be able to make transactions using FingerTips Bank's saving and current accounts anymore "<<endl;
        cout<<"to continue press 1, to return to main menu press 0"<<endl;
        cout<<"Your choice : ";
        cin>> choice;
        if(choice == 1){
            removeAccount(curCust);
            filewrite();
            cout<<"\nYour FingerTips Account has been succesful removed \n"<<endl;
            system("pause");
            Bank();
        }
        }
        else if(choice ==10){
            cout<<"\n1 : Saving account \n2 : Current account"<<endl;
            cout<<"Your Choice : ";
            cin>>choice;
            if(choice ==1){
                saving->bank_statement();
            }else if(choice==2){
                current->bank_statement();}
            else{Menu();}
        system("pause");
        Menu();
    }
}
void Bank::removeAccount(Customer *customer){
    vector<Customer *>::iterator ptr;
    ptr = find(database.begin(),database.end(),customer);
    if(ptr !=database.end()){
       database.erase(ptr);
       }
}
void Bank::terminate(){
    filewrite();
    exit(0);
}
void Bank::VirtualCard(string tittle,string name,string surname,long int acc){
     cout<<"\n********************************************************FingerTips Bank***********************************************************\n";
    cout<<"*********************************************************Virtual Card*************************************************************\n";
    Virtual_card virtualcard;
    virtualcard.tittle = tittle;
    virtualcard.name = name;
    virtualcard.surname = surname;
    virtualcard.account_no = acc;
    virtualcard.display();
}
void Bank::administrator(){
    system("cls");
    cout<<"\n*******************************************************FingerTips Bank**********************************************************\n";
    cout<<"*************************************************************Login********************************************************";
    string username, password;
    cout<< "\nEnter the username  : ";
    cin>>username;
    cout<< "Enter the Password  : ";
    cin>>password;
    if(username == administrator_userName && password == code){
        system("cls");
        cout<<"\n*******************************************************FingerTips Bank**********************************************************\n";
        cout<<"**********************************************************Administrator********************************************************\n";
        display();
        system("pause");
        Bank();
    }else{
        cout<<"\nIncorrect Login Details, you are not Fingertips Bank administrator, to return to welcome window press 1"<<endl;
        system("color 94");
        system("pause");
        system("Color 79");
        Bank();
    }
}
