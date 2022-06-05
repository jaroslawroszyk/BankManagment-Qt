#pragma once
#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

namespace Ui { class LoginWindow; }

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();
    bool loginConnect();
    void loginDissconect();

private slots:
    void on_actionExit_triggered();
    void on_actionAbout_triggered();
    void on_LoginButton_clicked();
    void on_login_userid_returnPressed();
    void on_login_password_returnPressed();

private:
    Ui::LoginWindow *ui;
    QSqlDatabase loginDatabase;
    void showMenuWindow();
    QString pathToDatabase = "./sql/Login.db";
    void setCurrentWindow();
};
