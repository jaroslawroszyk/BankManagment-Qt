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
    QDate date;
public:
    QDate getDate();
    void setDate(QDate);
};

//Account Class

class Account
{
    QString accountNumber;
    QString accountType;
    QString balance;
    bool status;
public:
    void setAccountNumber(QString);
    void setAccountType(QString);
    void setBalance(QString);
    bool getStatus();
    void setStatus(bool);
    QString getAccountNumber();
    QString getAccountType();
    QString getBalance();
};

//Password class

struct Password
{
private:
    QString accountPassword;
public:
    void setPassword(QString);
    QString getPassword();
};

//Personal class

class Personal
{
    QString mobileNumber;
    QString gender;
    QString nationality;
    QString address;
public:
    void setMobileNumber(QString);
    void setGender(QString);
    void setAddress(QString);
    void setNationality(QString);
    QString getNationality();
    QString getMobileNumber();
    QString getGender();
    QString getAddress();
    Date birthDate;
};

//Saving Account Class

class SavingAccount{
private:
    double rate;
public:
    void setRate(double);
    double getRate();
    Customer name;
    Customer father;
    Account saving;
    Personal info;
    Password pin;
    Date accountCreated;
    Date account_expire;
};

//Current Account Class

class CurrentAccount
{
public:
    Customer name;
    Customer father;
    Customer grandfather;
    Account current;
    Personal info;
    Password pin;
    Date accountCreated;
    Date accountExpire;
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
    QString bankName;
public:
    Account data;
    Customer holder;
    Customer by;
    Date deposit;
    void setMode(QString);
    void setChequeno(QString);
    void setBankName(QString);
    QString getMode();
    QString getchequeno();
    QString getBankName();
};

//Single Entry Data

class single_entry_data{
private:
    QString accountNumber;
    QString address;
    QString naration;
    QString amt;
    QString balance;
public:
    Customer name;
    Date dates;
    void setAccountNumber(QString);
    void setAddress(QString);
    void setnaration(QString);
    void setAmount(QString);
    void setbalance(QString);
    QString getAccountNumber();
    QString getAddress();
    QString getNaration();
    QString getAmount();
    QString getBalance();

};
