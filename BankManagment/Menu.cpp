#include "Menu.h"
#include "ui_Menu.h"

Menu::Menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    this->setFixedSize(350,400);
    this->setWindowTitle("Menu");
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_pushButton_clicked()
{
    QMessageBox::information(this,"Menu","New Menu");
}

