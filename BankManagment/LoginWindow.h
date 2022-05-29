#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class LoginWindow; }
QT_END_NAMESPACE

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();
private slots:
    void on_LoginButton_clicked();

    void on_actionExit_triggered();

private:
    Ui::LoginWindow *ui;
};
#endif // MAINWINDOW_H
