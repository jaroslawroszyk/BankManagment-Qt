#pragma once
#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

namespace Ui {
class OpenAccount;
}

class OpenAccount : public QWidget
{
    Q_OBJECT


public:
    explicit OpenAccount(QWidget *parent = nullptr);
    ~OpenAccount();
    bool connect();
    void dissconect();
    void setdata(QString ,QString,QString,bool);
    void setAccountNumber();
    int getAccountNumber();

private:
    Ui::OpenAccount *ui;
    QSqlDatabase db;
};
