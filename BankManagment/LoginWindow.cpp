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

void LoginWindow::on_LoginButton_clicked()
{
    QString username = ui->LoginBox->text();
    QString password = ui->PasswordBox->text();

    if(username == "t" and password == "t") //testing data
    {
        QMessageBox::information(this,"Login","Username and password is correct");
    }
    else
    {
        QMessageBox::warning(this,"Login","Username and password is not correct");
    }
}

