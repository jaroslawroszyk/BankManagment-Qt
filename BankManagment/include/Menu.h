#pragma once
#include <QMessageBox>
#include <QDialog>

namespace Ui
{
class Menu;
}

class Menu : public QDialog
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

private slots:
//    void on_listWidgetForAcc_currentTextChanged(const QString &currentText);
//    void on_listWidgetForAcc_entered(const QModelIndex &index);
    void on_Account_Select_clicked();

//    void on_Transactions_select_clicked(); //need
//    void on_Raport_select_clicked(); //need

private:
    Ui::Menu *ui;
    void addContentInWindow();
};
