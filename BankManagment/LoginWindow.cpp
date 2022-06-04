#include "./ui_LoginWindow.h"
#include "LoginWindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QDesktopWidget>

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

bool LoginWindow::loginConnect()
{
//    QString path = QCoreApplication::applicationDirPath() + "sql/Login.sql";
    //todo: repair a path of database
    loginDatabase = QSqlDatabase::addDatabase("QSQLITE");
    loginDatabase.setDatabaseName("/home/jarek/ProjectInQt/BankManagment-Qt/BankManagment/sql/Login.sql"); //or Login.db
    if(loginDatabase.open())
    {
         QMessageBox::information(this,"Login suc","xd");
        return true;
    }
//    return loginDatabase.open() ? true : false;
    return false;
}

void LoginWindow::loginDissconect()
{
    loginDatabase.close();
    loginDatabase.removeDatabase(QSqlDatabase::defaultConnection);
}

void LoginWindow::on_LoginButton_clicked()
{
    QString username = ui->login_userid->text();
    QString password = ui->login_password->text();

    if(username == NULL or password == NULL)
    {
        QMessageBox::warning(this,"Login error","Please Enter correct data");
    }
    else
    {
        LoginWindow::loginConnect();
        QSqlQuery query;
//        query.prepare("SELECT * FROM LoginData WHERE login='"+username+"' and password='"+password+"'");
       query.prepare("Select * from LoginData WHERE login='username' and password='password'");
        query.exec();
        LoginWindow::loginDissconect();
    }
}

//todo: add action with about us

void LoginWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void LoginWindow::on_login_userid_returnPressed()
{
    LoginWindow::on_LoginButton_clicked();
}

void LoginWindow::on_login_password_returnPressed()
{
    LoginWindow::on_LoginButton_clicked();
}

