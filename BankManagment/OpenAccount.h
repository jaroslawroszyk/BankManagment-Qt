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
    void setdata(QString ,QString,QString,bool);
    bool checknull();
    bool conn();
    void disconn();
    saving_account getsavingdata();
    current_account getcurrentdata();
    bool check_account_no(int);
    int get_account_no();
    double getrate(QString);
    void cleardata();
    void sa_to_database(saving_account);
    void ca_to_database(current_account);
    void setacc_no();
    void setoff();
    void seton();
    saving_account getupdatedata();
    bool updatedata(saving_account);
    void load_data(QString);

private slots:
    void on_ao_push_clicked();

    void on_ao_back_clicked();

    void on_ao_acc_no_returnPressed();

private:
    Ui::OpenAccount *ui;
    QSqlDatabase mydb;
};
