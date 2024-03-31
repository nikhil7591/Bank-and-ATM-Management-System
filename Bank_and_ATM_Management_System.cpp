#include <iostream>
#include <fstream>
#include <conio.h>
#include <Windows.h>

using namespace std;

// Introduction
void introduction(){
    system("cls");
    cout<<"\n\n\n\n\n\t";
    for(int i=0;i<60;i++){
        cout<<"*";
    }
    cout<<"\n\t ";
    for(int i=0;i<58;i++){
        cout<<"*";
    }
    cout<<"\n\t  ";
    for(int i=0;i<56;i++){
        cout<<"*";
    }
    cout<<"\n\n\t\t\t Bank & ATM Management System\n\n\t\t\t\t Project In C++\n\n\t  ";
    for(int i=0;i<56;i++){
        cout<<"*";
    }
    cout<<"\n\t ";
    for(int i=0;i<58;i++){
        cout<<"*";
    }
    cout<<"\n\t";
    for(int i=0;i<60;i++){
        cout<<"*";
    }
    getch();
    system("cls");
}

class bank {
private:
    string id, pass, name, fname, address, phone,pin;
    float balance;

public:
    void menu();
    void bank_management();
    void atm_management();
    void new_user();
    void already_user();
    void deposit();
    void withdraw();
    void transfer();
    void payment();
    void search_user();
    void edit_user();
    void delete_user();
    void show_all();
    void payment_all_record();
    void user_balance();
    void atm_withdraw();
    void atm_detail();
    void writeToFile(const string& filename, const string& data);
};

// Write data to file
void bank::writeToFile(const string& filename, const string& data) {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << data << endl;
        file.close();
    }
    else {
        cout << "Unable to open file for writing.";
    }
}

// menu portal --> starting page
void bank::menu() {
    p:
    system("cls");
    int choice;
    char ch;
    string pin, pass, email;
    cout << "\tBank Management System" << endl;
    cout << "\n\t\tMain Menu";
    cout << "\n\n 1. Bank Management";
    cout << "\n 2. ATM Management";
    cout << "\n 3. Exit";
    cout << "\n\n Enter your Choice : ";
    cin >> choice;
    switch (choice) {
    case 1: {
        system("cls");
        cout << "\t\tLogin Account";
        cout << "\n\n Email : ";
        cin >> email;
        cout << " Pin Code : ";
        for (int i = 1; i <= 6; i++) {
            ch = getch();
            pin += ch;
            cout << "*";
        }
        cout << "\n Password : ";
        for (int i = 1; i <= 4; i++) {
            ch = getch();
            pass += ch;
            cout << "*";
        }

        if (email == "abc@gmail.com" && pin == "759100" && pass == "1234") {
            bank_management();
        }
        else {
            cout << "\n\n Your E-mail, Pin & Password is Wrong...";
        }
        break;
    }
    case 2: {
        atm_management();
        break;
    }
    case 3: {
        exit(0);
        break;
    }
    default:
        cout << "\n\n Invalid Value.. Please try Again..";
    }
    getch();
    goto p;
}

// bank management system portal --> starting
void bank::bank_management() {
    p:
    system("cls");
    int choice;
    cout << "\t\tBank Management system" << endl;
    cout << "\n1. New User" << endl;
    cout << "2. Already User" << endl;
    cout << "3. Deposit Option" << endl;
    cout << "4. Withdraw Option" << endl;
    cout << "5. Transfer Option" << endl;
    cout << "6. Payment Option" << endl;
    cout << "7. Search User Record" << endl;
    cout << "8. Edit User Record" << endl;
    cout << "9. Delete User Record" << endl;
    cout << "10. Show All Record" << endl;
    cout << "11. Payment Records" << endl;
    cout << "12. Go Back" << endl;
    cout << "\n Enter Your Choice : ";
    cin >> choice;

    switch (choice) {
    case 1: {
        new_user();
        break;
    }
    case 2: {
        already_user();
        break;
    }
    case 3: {
        deposit();
        break;
    }
    case 4: {
        withdraw();
        break;
    }
    case 5: {
        transfer();
        break;
    }
    case 6: {
        payment();
        break;
    }
    case 7: {
        search_user();
        break;
    }
    case 8: {
        edit_user();
        break;
    }
    case 9: {
        delete_user();
        break;
    }
    case 10: {
        show_all();
        break;
    }
    case 11: {
        payment_all_record();
        break;
    }
    case 12: {
        menu();
        break;
    }
    default:
        cout << "\n\n Invalid Value.. Please try Again..";
    }
    getch();
    goto p;
}

// new user function
void bank :: new_user(){
    p:
    system("cls");
    fstream file;
    int p; // for pin
    float b; // balance
    string n,fn,pas,ad,ph,i; // name, father_name,pasword,address,phonenumber,id

    cout<<"\t\tAdd New User"<<endl;
    cout<<"\n User ID : ";
    cin>>id;
    cout<<"\n Name : ";
    cin>>name;
    cout<<"\n Father Name : ";
    cin>>fname;
    cout<<"\n Address : ";
    cin>>address;
    cout<<"\n Pin Code (5 digit) : ";
    cin>>pin;
    cout<<"\n Password (8 digit): ";
    cin>>pass;
    cout<<"\n Phone Number : ";
    cin>>phone;
    cout<<"\n Current Balance : ";
    cin>>balance;

    file.open("bank.txt",ios::in);
    if(!file){
        file.open("bank.txt",ios::app|ios::out);
        file<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
        file.close();
    }
    else{
        file>>i>>n>>fn>>ad>>p>>pas>>ph>>b;
        while(!file.eof()){
            if(i == id){
                cout<<"\n User Id Already Exist...";
                getch();
                goto p;
            }
            file>>i>>n>>fn>>ad>>p>>pas>>ph>>b;
        }
        file.close();
        file.open("bank.txt",ios::app|ios::out);
        file<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
        file.close();
    }
    cout<<"\n\n New User Account Created Successfully..!!";
}

// already user account
void bank:: already_user(){
    system("cls");
    fstream file;
    string t_id;
    int found = 0;
    cout<<"\n\n\t\t\t Alerady User Account";
    file.open("bank.txt",ios::in);
    if(!file){
        cout<<"\n\n File Opening Error..";
    }
    else{
        cout<<"\n\n User ID : ";
        cin>>t_id;
        file>>id>>name>>fname >>address>>pin>>pass>>phone>>balance;
        while (!file.eof())
        {
            if(t_id == id){
                system("cls");
                cout<<"\n\n\t\t\t Alerady User Account";
                cout<<"\n\nUser ID : "<<id<<"\tPin Code : "<<pin<<"\tPassword : "<<pass<<endl;
                found++;
            }
            file>>id>>name>>fname >>address>>pin>>pass>>phone>>balance;
        }
        file.close();
        if(found==0){
            cout<<"\n\n User ID Can't Found...";
        }     
    }
}

// deposit function
void bank :: deposit(){
    system("cls");
    fstream file,file1;
    string t_id;
    float dep;
    int found = 0;
    cout<<"\n\n\t\tDeposit Amount Option";
    file.open("bank.txt",ios::in);
    if(!file){
        cout<<"\n\n File Opening Error...";
    }
    else{
        
        cout<<"\n\n User ID : ";
        cin>>t_id;
        file1.open("bank1.txt",ios::app|ios::out);
        file>>id>>name>>fname >>address>>pin>>pass>>phone>>balance;
        while (!file.eof())
        {
            if(t_id == id){
                cout<<"\n\n Enter Amount For Deposit : ";
                cin>>dep;
                balance += dep;
                file1<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
                cout<<"\n\n Your Amount "<<dep<<" Successfully Deposite...";
                found++;
            }
            else{
                file1<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
            }
            file>>id>>name>>fname >>address>>pin>>pass>>phone>>balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt","bank.txt");
        if(found==0){
            cout<<"\n\n User ID Can't Found...";
        }
    }
}

// withdraw function
void bank :: withdraw(){
    system("cls");
    fstream file,file1;
    string t_id;
    float with;
    int found = 0;
    cout<<"\n\n\t\tWithdraw Amount Option";
    file.open("bank.txt",ios::in);
    if(!file){
        cout<<"\n\n File Opening Error...";
    }
    else{
        
        cout<<"\n\n User ID : ";
        cin>>t_id;
        file1.open("bank1.txt",ios::app|ios::out);
        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        while (!file.eof())
        {
            if(t_id == id){
                cout<<"\n\n Enter Amount For Withdraw : ";
                cin>>with;
                if(with<=balance){
                    balance -= with;
                    file1<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
                    cout<<"\n\n Your Amount "<<with<<" Successfully Withdraw...";
                }
                else{
                    file1<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
                    cout<<"\n\nYour Current Balance "<<balance<<" is Less...";
                }
                found++;
            }
            else{
                file1<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
            }
            file>>id>>name>>fname >>address>>pin>>pass>>phone>>balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt","bank.txt");
        if(found==0){
            cout<<"\n\n User ID Can't Found...";
        }
    }
}

// Transfer function
void bank :: transfer(){
    fstream file,file1;
    system("cls");
    string s_id,r_id;
    float amount;
    int found = 0;
    cout<<"\n\n\t\t\tPayment Transfer Option";
    file.open("bank.txt",ios::in);
    if(!file){
        cout<<"\n\n File Opening Error...";
    }
    else{
        cout<<"\n\n Sender User ID For Transction : ";
        cin>>s_id;
        cout<<"\n\n Reciver User ID For Transction : ";
        cin>>r_id;
        cout<<"\n\n Enter Transfer Amount : ";
        cin>>amount;
        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        while(!file.eof()){
            if(s_id == id && amount<=balance || r_id == id){
                found++;
            }
            file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        }
        file.close();
        if(found == 2){
            file.open("bank.txt",ios::in);
            file1.open("bank1.txt",ios::app|ios::out);
            file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
            while (!file.eof()){
                if(s_id == id){
                    balance -= amount;
                    file1<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
                }
                else if(r_id == id){
                    balance +=amount;
                    file1<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
                    cout<<"\n\n Transction Successfull....";
                }
                else{
                    file1<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
                }
                file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
            }
            file.close();
            file1.close();
            remove("bank.txt");
            rename("bank1.txt","bank.txt");
        }
        else{
            cout<<"\n\nBoth Transction User ID's & Balance Invalid...";
        }
    }

}

// Payment function
void bank :: payment(){
    system("cls");
    fstream file,file1;
    string t_id,b_name;
    float amount;
    int found =  0;
    SYSTEMTIME x;
    cout<<"\n\n\t\t Bills Payment Option";
    file.open("bank.txt",ios::in);
    if(!file){
        cout<<"\n\n FIle Opening Error...";
    }
    else{
        cout<<"\n\n Enter User ID : ";
        cin>>t_id;
        cout<<"\n\n Bill Name : ";
        cin>>b_name;
        cout<<"\n\n Bill Amount : ";
        cin>>amount;
        file1.open("bank1.txt",ios::app|ios::out);
        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        while(!file.eof()){
            if(t_id == id && amount<=balance){
                balance -= amount;
                file1<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
                found++;
            }
            else{
                file1<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
            }
            file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt","bank.txt");

        if(found == 1){
            GetSystemTime(&x);
            file.open("bill.txt",ios::app|ios::out);
            file<<t_id<<"  "<<b_name<<"  "<<amount<<"  "<<x.wDay<<"/"<<x.wMonth<<"/"<<x.wYear<<"  "<<x.wHour << ":" << x.wMinute << ":" << x.wSecond<<"\n";
            file.close();
            cout<<"\n\n\t"<<b_name<<" Bill Pay Successfull....";
        }
        else{
            cout<<"\n\n User ID or Amount Invalid....";
        }
    }
}

// Search User Record function
void bank:: search_user(){
    system("cls");
    fstream file;
    string t_id;
    int found =0;
    cout<<"\n\n\t\t\tSearch User Record";
    file.open("bank.txt",ios::in);
    if(!file){
        cout<<"\n\nFile Opening Error...";
    }
    else{
        cout<<"\n\n User ID : ";
        cin>>t_id;
        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        while(!file.eof()){
            if(t_id == id){
                cout<<"\n\n\t\t\t\tUser Record";
                cout<<"\n\n";
                cout<<"[\nUser ID : "<<id<<","<<endl;
                cout<<"Name : "<<name<<","<<endl;
                cout<<"Father Name : "<<fname<<","<<endl;
                cout<<"Address : "<<address<<","<<endl;
                cout<<"Pin : "<<pin<<","<<endl;
                cout<<"Password : "<<pass<<","<<endl;
                cout<<"Phone No. : "<<phone<<","<<endl;
                cout<<"Current Balance : "<<balance<<"\n]"<<endl;
                found++;
            }
            file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        }
        file.close();
        if(found == 0){
            cout<<"\n\nUser ID Can't Found....";
        }
    }
}

// Edit User Record function
void bank:: edit_user(){
    system("cls");
    fstream file,file1;
    string t_id,n,fn,a,p,ph;
    int pi,found = 0;

    cout<<"\n\n\t\t\tEdit User Record";
    file.open("bank.txt",ios::in);
    if(!file){
        cout<<"\n\nFile Opening Error...";
    }
    else{
        cout<<"\n\nUser ID : ";
        cin>>t_id;

        file1.open("bank1.txt",ios::app|ios::out);
        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        while(!file.eof()){
            if(t_id == id){
                cout<<"\n Name : ";
                cin>>n;
                cout<<"\n Father Name : ";
                cin>>fn;
                cout<<"\n Address : ";
                cin>>a;
                cout<<"\n Pin Code (5 digit) : ";
                cin>>pi;
                cout<<"\n Password : ";
                cin>>p;
                cout<<"\n Phone Number : ";
                cin>>ph;
                file1<<id<<" "<<n<<" "<<fn<<" "<<a<<" "<<pi<<" "<<p<<" "<<ph<<" "<<balance<<"\n";
                cout<<"\n\n\t\t\t\tUser Record Edit Successfull...";
                found++;
            }
            else{
                file1<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
            }
            file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt","bank.txt");
        if(found == 0){
            cout<<"\n\nUser ID Can't Found....";
        }
    }
}

// Delete User Record function
void bank :: delete_user(){
    system("cls");
    fstream file,file1;
    string t_id;
    int found = 0;

    cout<<"\n\n\t\t\tEdit User Record";
    file.open("bank.txt",ios::in);
    if(!file){
        cout<<"\n\nFile Opening Error...";
    }
    else{
        cout<<"\n\nUser ID : ";
        cin>>t_id;

        file1.open("bank1.txt",ios::app|ios::out);
        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        while(!file.eof()){
            if(t_id == id){
                cout<<"\n\n\t\t\t\tUser Record Delete Successfull...";
                found++;
            }
            else{
                file1<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
            }
            file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt","bank.txt");
        if(found == 0){
            cout<<"\n\nUser ID Can't Found....";
        }
    }
}


// Show All Record function
void bank :: show_all(){
    system("cls");
    fstream file;
    cout<<"\n\n\t\t\tShow All User's Records"<<endl;
    file.open("bank.txt",ios::in);
    if(!file){
        cout<<"\n\nFile OPening Error....";
    }
    else{
        int found = 0;
        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        while(!file.eof()){
            cout<<"[\n\tUser ID : "<<id<<","<<endl;
            cout<<"\tName : "<<name<<","<<endl;
            cout<<"\tFather Name : "<<fname<<","<<endl;
            cout<<"\tAddress : "<<address<<","<<endl;
            cout<<"\tPin : "<<pin<<","<<endl;
            cout<<"\tPassword : "<<pass<<","<<endl;
            cout<<"\tPhone No. : "<<phone<<","<<endl;
            cout<<"\tCurrent Balance : "<<balance<<"\n]"<<endl;
            file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
            found++;
        }
        file.close();
        if(found == 0){
            cout<<"\n\n Data Base is Empty...";
        }
    }
}

// Payment All Record function
void bank :: payment_all_record(){
        system("cls");
    fstream file;
    cout<<"\n\n\t\t\tShow All Payment Records"<<endl;
    file.open("bill.txt",ios::in);
    if(!file){
        cout<<"\n\nFile Opening Error....";
    }
    else{
        int found = 0;
        float amount;
        string b_name,c_date,c_time;        
        file>>id>>b_name>>amount>>c_date>>c_time;
        while(!file.eof()){
            cout<<"[\n\tUser ID : "<<id<<","<<endl;
            cout<<"\tBill Name : "<<b_name<<","<<endl;
            cout<<"\tBill Amount : "<<amount<<","<<endl;
            cout<<"\tDate : "<<c_date<<","<<endl;
            cout<<"\tTime : "<<c_time<<"\n]"<<endl;
            file>>id>>b_name>>amount>>c_date>>c_time;
            found++;
        }
        file.close();
        if(found == 0){
            cout<<"\n\n Data Base is Empty...";
        }
    }
}

// ATM management system portal --> starting
void bank::atm_management() {
    p:
    system("cls");
    int choice;
    cout << "\t\tATM Management system" << endl;
    cout << "\n1. User Login & Check Balance" << endl;
    cout << "2. Withdraw Amount" << endl;
    cout << "3. Account Details" << endl;
    cout << "4. Go Back" << endl;
    cout << "\n Enter Your Choice : ";
    cin >> choice;

    switch (choice) {
    case 1: {
        user_balance();
        break;
    }
    case 2: {
        atm_withdraw();
        break;
    }
    case 3: {
        atm_detail();
        break;
    }
    case 4: {
        menu();
        break;
    }
    default:
        cout << "\n\n Invalid Value.. Please try Again..";
        cout<<"\n=========================================================="<<endl;
    }
    getch();
    goto p;
}

// all function for ATM Management System

// User Login & Check Balance
void bank :: user_balance(){
    system("cls");
    fstream file;
    string t_id,t_pass,t_pin;
    int found = 0;
    char ch;
    cout<<"\n\n\t\t\tUser Login & Check Balance";
    file.open("bank.txt",ios::in);
    if(!file){
        cout<<"\n\nFile Opening Error....";
    }
    else{
        cout<<"\n\nUser ID : ";
        cin>>t_id;
        cout<<"\nPin Code : ";
        for(int i=1;i<=5;i++){
            ch = getch();
            t_pin +=ch;
            cout<<"*";
        }
        cout<<"\nPassword : ";
        for(int i=1;i<=8;i++){
            ch = getch();
            t_pass +=ch;
            cout<<"*";
        }
        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        while(!file.eof()){
            if(t_id == id && t_pin == pin && t_pass == pass){
                cout<<"\n\n\t\t\tYour Current Balance is : "<<balance;
                cout<<"\n=========================================================="<<endl;
                found++;
            }
            file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        }
        file.close();
        if(found == 0){
            cout<<"\n\n\t\tUser ID, Pin & Password Invalid...";
            cout<<"\n=========================================================="<<endl;
        }
    }
}
// ATM Withdraw function
void bank :: atm_withdraw(){
    fstream file,file1;
    string t_id,t_pass,t_pin;
    char ch;
    float with;
    int found = 0;
    system("cls");
    cout<<"\n\n\t\tWithdraw Amount Option";
    file.open("bank.txt",ios::in);
    if(!file){
        cout<<"\n\n File Opening Error...";
    }
    else{
        cout<<"\n\n User ID : ";
        cin>>t_id;
        cout<<"\nPin Code : ";
        for(int i=1;i<=5;i++){
            ch = getch();
            t_pin +=ch;
            cout<<"*";
        }
        cout<<"\nPassword : ";
        for(int i=1;i<=8;i++){
            ch = getch();
            t_pass +=ch;
            cout<<"*";
        }
        file1.open("bank1.txt",ios::app|ios::out);
        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        while (!file.eof())
        {
            if(t_id == id && t_pass == pass && t_pin == pin){
                cout<<"\n\n Enter Amount For Withdraw : ";
                cin>>with;
                if(with<=balance){
                    balance -= with;
                    file1<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
                    cout<<"\n\n Your Amount "<<with<<" Successfully Withdraw...";
                    cout<<"\n\nYour Current Balance : "<<balance;
                    cout<<"\n=========================================================="<<endl;
                }
                else{
                    file1<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
                    cout<<"\n\nYour Current Balance "<<balance<<" is Less...";
                    cout<<"\n=========================================================="<<endl;
                }
                found++;
            }
            else{
                file1<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
            }
            file>>id>>name>>fname >>address>>pin>>pass>>phone>>balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt","bank.txt");
        if(found==0){
            cout<<"\n\n User ID Can't Found...";
            cout<<"\n=========================================================="<<endl;
        }
    }
}
// details function
void bank :: atm_detail(){
    fstream file;
    string t_id,t_pass,t_pin;
    char ch;
    int found = 0;
    system("cls");
    cout<<"\n\n\t\tCheck Details Option";
    file.open("bank.txt",ios::in);
    if(!file){
        cout<<"\n\n File Opening Error...";
    }
    else{
        cout<<"\n\n User ID : ";
        cin>>t_id;
        cout<<"\nPin Code : ";
        for(int i=1;i<=5;i++){
            ch = getch();
            t_pin +=ch;
            cout<<"*";
        }
        cout<<"\nPassword : ";
        for(int i=1;i<=8;i++){
            ch = getch();
            t_pass +=ch;
            cout<<"*";
        }
        cout<<"\n"<<endl;
        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        while (!file.eof())
        {
            if(t_id == id && t_pass == pass && t_pin == pin){
                cout<<"[\n\tUser ID : "<<id<<","<<endl;
                cout<<"\tName : "<<name<<","<<endl;
                cout<<"\tFather Name : "<<fname<<","<<endl;
                cout<<"\tAddress : "<<address<<","<<endl;
                cout<<"\tPin : "<<pin<<","<<endl;
                cout<<"\tPassword : "<<pass<<","<<endl;
                cout<<"\tPhone No. : "<<phone<<","<<endl;
                cout<<"\tCurrent Balance : "<<balance<<"\n]"<<endl;
                cout<<"\n=========================================================="<<endl;
                found++;
            }
            file>>id>>name>>fname >>address>>pin>>pass>>phone>>balance;
        }
        file.close();
        if(found==0){
            cout<<"\n\n User ID Can't Found...";
            cout<<"\n=========================================================="<<endl;
        }
    }
}

int main() {
    bank obj;
    introduction();
    obj.menu();
    return 0;
}