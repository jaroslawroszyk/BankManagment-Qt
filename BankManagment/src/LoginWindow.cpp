#include "./ui_LoginWindow.h"
#include "include/LoginWindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QDesktopWidget>
#include "include/Menu.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    this->setFixedSize(300,200);
    this->setWindowTitle("Authentication");
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::showMenuWindow()
{
    Menu *win=new Menu;
    this->hide();
    win->show();
}

bool LoginWindow::loginConnect()
{
    loginDatabase = QSqlDatabase::addDatabase("QSQLITE");
    loginDatabase.setDatabaseName(pathToDatabase);
    return loginDatabase.open() ? true : false;
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
        query.prepare("SELECT * FROM LoginData WHERE login='"+username+"' and password='"+password+"'");
        query.exec();
        if(query.next())
        {
            showMenuWindow();
        }
        else
        {
            QMessageBox::information(this,"Login","Incorrect Login or Passowrd");
        }
        LoginWindow::loginDissconect();
    }
}

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

void LoginWindow::on_actionAbout_triggered()
{
    QMessageBox::warning(this,"Jarus","Author name: Jaroslaw\nDev name: Jaroslaw");
}
