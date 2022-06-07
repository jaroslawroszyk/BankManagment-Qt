#include "OpenAccount.h"
#include "ui_OpenAccount.h"

OpenAccount::OpenAccount(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OpenAccount)
{
    ui->setupUi(this);
}

OpenAccount::~OpenAccount()
{
    delete ui;
}

bool OpenAccount::connect()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/jarek/ProjectInQt/BankManagment-Qt/BankManagment/sql/AccountDatabase.db");
    return db.open() ? true : false; //refactor private fields db to AccountDatabase
}
void OpenAccount::dissconect()
{
    db.close();
    db.removeDatabase(QSqlDatabase::defaultConnection);
}

void OpenAccount::setdata(QString title,QString pushButton,QString backButton,bool status)
{
    setWindowTitle(title);
    ui->AccountPush->setText(pushButton);
    ui->AccountBack->setText(backButton);
    ui->accountNumber->setReadOnly(status);
}

void OpenAccount::setAccountNumber()
{
    ui->accountNumber->setText(QString::number(OpenAccount::getAccountNumber()));
    ui->accountNumber->setReadOnly(true);
}

int OpenAccount::getAccountNumber()
{
    int number = 0;
    OpenAccount::connect();
    QSqlQuery query;
    query.prepare("SELECT max([Account Number]) FROM account");
    query.exec();
    while(query.next())
    {
        number = query.value(0).toInt();
    }
    return number+1;
}
