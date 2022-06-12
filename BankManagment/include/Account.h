#pragma once

#include <QString>
#include <QDate>

//Customer Class

class Customer
{
    QString name;
public:
    void setname(QString);
    QString getname();
};

//Date Class

class Date
{
    QDate dates;
public:
    QDate getdate();
    void setdate(QDate);
};

//Account Class

class Account
{
    QString acc_no;
    QString acc_type;
    QString balance;
    bool status;
public:
    void setaccount_no(QString);
    void setaccount_type(QString);
    void setbalance(QString);
    bool getstatus();
    void setstatus(bool);
    QString getaccount_no();
    QString getaccount_type();
    QString getbalance();
};

//Password class

class Password
{ // this may be a struct
    QString pass;
public:
    void setpassword(QString);
    QString getpassword();
};

//Personal class

class Personal
{
    QString mob_no;
    QString gender;
    QString nationality;
    QString address;
public:
    void setmobileno(QString);
    void setgender(QString);
    void setaddress(QString);
    void setnationality(QString);
    QString getnationality();
    QString getmobileno();
    QString getgender();
    QString getaddress();
    Date birth;
};

//Saving Account Class

class SavingAccount{
private:
    double rate;
public:
    void setrate(double);
    double getrate();
    Customer name;
    Customer father;
    Customer grandfather;
    Account saving;
    Personal info;
    Password pin;
    Date account_created;
    Date account_expire;
};

//Current Account Class

class CurrentAccount{
public:
    Customer name;
    Customer father;
    Customer grandfather;
    Account current;
    Personal info;
    Password pin;
    Date account_created;
    Date account_expire;
};

//Withdraw Data Class

class WithdrawData{
public:
    Customer name;
    Date withdraw;
    Password pin;
    Account data;
};

//Deposit Data Class

class DepositData{
private:
    QString mode;
    QString cheque_no;
    QString bank_name;
public:
    Account data;
    Customer holder;
    Customer by;
    Date deposit;
    void setmode(QString);
    void setchequeno(QString);
    void setbankname(QString);
    QString getmode();
    QString getchequeno();
    QString getbankname();
};

//Single Entry Data

class single_entry_data{
private:
    QString acc_no,address,naration,amt,balance;
public:
    Customer name;
    Date dates;
    void setacc_no(QString);
    void setaddress(QString);
    void setnaration(QString);
    void setamount(QString);
    void setbalance(QString);
    QString getacc_no();
    QString getaddress();
    QString getnaration();
    QString getamount();
    QString getbalance();

};
