#pragma once
#include <QMessageBox>
#include <QDialog>

namespace Ui {
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

//    void on_listWidgetForTran_currentTextChanged(const QString &currentText);
//    void on_Transactions_select_clicked();

//    void on_listWidget_Raport_currentTextChanged(const QString &currentText);
//    void on_Raport_select_clicked();



private:
    Ui::Menu *ui;
    void addContentInWindow();
};
