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

void LoginWindow::centerAndResize()
{
    QSize availableSize = qApp->desktop()->availableGeometry().size();
       int width = availableSize.width();
       int height = availableSize.height();
       qDebug() << "Available dimensions " << width << "x" << height;
       width *= 0.9; // 90% of the screen size
       height *= 0.9; // 90% of the screen size
       qDebug() << "Computed dimensions " << width << "x" << height;
       QSize newSize( width, height );
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

