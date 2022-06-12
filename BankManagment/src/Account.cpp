#include "include/Account.h"

void Customer::setname(QString n)
{
    name=n;
}

QString Customer::getname()
{
    return name;
}

QDate Date::getDate()
{
    return date;
}

void Date::setDate(QDate k)
{
    date=k;
}

void Account::setAccountNumber(QString accNo)
{
    accountNumber=accNo;
}

void Account::setAccountType(QString type)
{
    accountType=type;
}

void Account::setBalance(QString bal)
{
    balance=bal;
}

QString Account::getAccountNumber()
{
    return accountNumber;
}

QString Account::getAccountType()
{
    return accountType;
}

QString Account::getBalance()
{
    return balance;
}

bool Account::getStatus()
{
    return status;
}

void Account::setStatus(bool stat)
{
    status=stat;
}

void Password::setPassword(QString passwd)
{
    accountPassword=passwd;
}

QString Password::getPassword()
{
    return accountPassword;
}

void Personal::setMobileNumber(QString mobile)
{
    mobileNumber=mobile;
}

void Personal::setGender(QString gen)
{
    gender=gen;
}

void Personal::setAddress(QString addr)
{
    address=addr;
}

void Personal::setNationality(QString natio)
{
    nationality=natio;
}

QString Personal::getNationality()
{
    return nationality;
}

QString Personal::getMobileNumber()
{
    return mobileNumber;
}

QString Personal::getGender()
{
    return gender;
}

QString Personal::getAddress()
{
    return address;
}

void SavingAccount::setRate(double rat)
{
    rate=rat;
}

double SavingAccount::getRate()
{
    return rate;
}

void DepositData::setMode(QString mod)
{
    mode=mod;
}

void DepositData::setChequeno(QString b)
{
    cheque_no=b;
}

void DepositData::setBankName(QString name)
{
    bankName=name;
}

QString DepositData::getMode()
{
    return mode;
}

QString DepositData::getchequeno()
{
    return cheque_no;
}

QString DepositData::getBankName()
{
    return bankName;
}

//Single Entry Data Implementation

void single_entry_data::setAccountNumber(QString accNumber)
{
    accountNumber=accNumber;
}

void single_entry_data::setAddress(QString adr)
{
    address=adr;
}

void single_entry_data::setnaration(QString nar)
{
    naration=nar;
}

void single_entry_data::setAmount(QString amount)
{
    amt=amount;
}

void single_entry_data::setbalance(QString bal)
{
    balance=bal;
}

QString single_entry_data::getAccountNumber()
{
    return accountNumber;
}

QString single_entry_data::getAddress()
{
    return address;
}

QString single_entry_data::getNaration()
{
    return naration;
}

QString single_entry_data::getAmount()
{
    return amt;
}

QString single_entry_data::getBalance()
{
    return balance;
}
