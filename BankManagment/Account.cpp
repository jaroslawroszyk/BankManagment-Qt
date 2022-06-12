#include "Account.h"

//Customer Class Implementation

void Customer::setname(QString n){
    name=n;
}

QString Customer::getname(){
    return name;
}

//Date Class Implementation

QDate Date::getdate(){
    return dates;
}

void Date::setdate(QDate k){
    dates=k;
}


//Account Class Implementation

void Account::setaccount_no(QString a){
    acc_no=a;
}

void Account::setaccount_type(QString b){
    acc_type=b;
}

void Account::setbalance(QString c){
    balance=c;
}

QString Account::getaccount_no(){
    return acc_no;
}

QString Account::getaccount_type(){
    return acc_type;
}

QString Account::getbalance(){
    return balance;
}

bool Account::getstatus(){
    return status;
}

void Account::setstatus(bool s){
    status=s;
}

//Password Class Implementation

void Password::setpassword(QString z){
    pass=z;
}

QString Password::getpassword(){
    return pass;
}

//Personal Class Implementation

void Personal::setmobileno(QString a){
    mob_no=a;
}

void Personal::setgender(QString b){
    gender=b;
}

void Personal::setaddress(QString c){
    address=c;
}

void Personal::setnationality(QString n){
    nationality=n;
}

QString Personal::getnationality(){
    return nationality;
}

QString Personal::getmobileno(){
    return mob_no;
}

QString Personal::getgender(){
    return gender;
}

QString Personal::getaddress(){
    return address;
}

//Saving Account Implementation

void SavingAccount::setrate(double k){
    rate=k;
}

double SavingAccount::getrate(){
    return rate;
}


//Deposit Data Implementation

void DepositData::setmode(QString a){
    mode=a;
}

void DepositData::setchequeno(QString b){
    cheque_no=b;
}

void DepositData::setbankname(QString c){
    bank_name=c;
}

QString DepositData::getmode(){
    return mode;
}

QString DepositData::getchequeno(){
    return cheque_no;
}

QString DepositData::getbankname(){
    return bank_name;
}

//Single Entry Data Implementation

void single_entry_data::setacc_no(QString a){
    acc_no=a;
}

void single_entry_data::setaddress(QString a){
    address=a;
}

void single_entry_data::setnaration(QString n){
    naration=n;
}

void single_entry_data::setamount(QString a){
    amt=a;
}

void single_entry_data::setbalance(QString b){
    balance=b;
}

QString single_entry_data::getacc_no(){
    return acc_no;
}

QString single_entry_data::getaddress(){
    return address;
}

QString single_entry_data::getnaration(){
    return naration;
}

QString single_entry_data::getamount(){
    return amt;
}

QString single_entry_data::getbalance(){
    return balance;
}
