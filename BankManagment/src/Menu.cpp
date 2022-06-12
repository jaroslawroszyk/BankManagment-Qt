#include "include/Menu.h"
#include "ui_Menu.h"
#include "include/OpenAccount.h"
#include <QMessageBox>
#include <QTabWidget>

Menu::Menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    this->setFixedSize(350,400);
    this->setWindowTitle("Menu");
    addContentInWindow();
}

Menu::~Menu()
{
    delete ui;
}

void Menu::addContentInWindow()
{
    QStringList tabAccount,tabTransactions,tabReport;
    tabAccount << "1. Open Account" << "2. Enquiry" << "3. Modify Account" << "4. Delete Account" << "5. Check Balance";
    tabTransactions<<"1. Deposit Ammount"<<"2. Withdraw Ammount";
    tabReport<<"1. Account Holders Detail" << "2. Raport from period";
    ui->listWidgetForAcc->addItems(tabAccount);
    ui->listWidgetForTran->addItems(tabTransactions);
    ui->listWidget_Raport->addItems(tabReport);
    ui->MenuWidget->setCurrentIndex(0);
}


//void Menu::on_listWidgetForAcc_currentTextChanged(const QString &currentText)
//{
////    1. Open Account" << "2. Check balance" << "3. Modify Account" << "4. Delete Account";
/// przyda sie do obrazkow
//    if(currentText == "1. Open Account")
//    {
//        ui->
//    }
//}

//void Menu::on_listWidgetForAcc_entered(const QModelIndex &index)
//{

//}

void Menu::on_Account_Select_clicked() //potrzebne
{
    /*
    "1. Open Account"
    "2. Check balance""
    "3. Modify Account
    "4. Delete Account"; */
    QString selected = ui->listWidgetForAcc->currentItem()->text();
    if(selected == "1. Open Account")
    {
        OpenAccount *winAccount = new OpenAccount;
        winAccount->setData("Open Account", "Create Account","Back",true);
        winAccount->setAccountNumber();
        this->hide();
        winAccount->show();
    }
}

//void on_Transactions_select_clicked(); // need
//void on_Raport_select_clicked(); // need

