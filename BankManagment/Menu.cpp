#include "Menu.h"
#include "ui_Menu.h"
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
    tabAccount << "1. Open Account" << "2. Check balance" << "3. Modify Account" << "4. Delete Account";
    tabTransactions<<"1. Deposit Ammount"<<"2. Withdraw Ammount";
    tabReport<<"1. Account Holders Detail" << "2. Raport from period";
    ui->listWidgetForAcc->addItems(tabAccount);
    ui->listWidgetForTran->addItems(tabTransactions);
    ui->listWidget_Raport->addItems(tabReport);
    ui->MenuWidget->setCurrentIndex(0);
}
