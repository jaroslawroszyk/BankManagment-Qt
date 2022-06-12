#pragma once
#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include "Account.h"

namespace Ui {
class OpenAccount;
}

class OpenAccount : public QWidget
{
    Q_OBJECT

public:
    explicit OpenAccount(QWidget *parent = nullptr);
    ~OpenAccount();
    void setData(QString ,QString,QString,bool);
    bool isNullData();
    bool Connect();
    void Disconnect();
    SavingAccount getSavingData();
    CurrentAccount getCurrentData();
    bool checkAccountNumber(int);
    int getAccountNumber();
    double getRate(QString);
    void clearData();
    void sendToSavingAccountDb(SavingAccount);
    void sendToCurrentAccountDb(CurrentAccount);
    void setAccountNumber();
    void setoff();
    void seton();
    SavingAccount getUpdateData();
    bool updateData(SavingAccount);
    void loadData(QString);

private slots:
    void on_ao_push_clicked();

    void on_ao_back_clicked();

    void on_ao_acc_no_returnPressed();

private:
    Ui::OpenAccount *ui;
    QSqlDatabase mydb;
    QString pathToDatabase = "./sql/AccountDatabase.db";
};
