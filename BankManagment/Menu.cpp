#include "Menu.h"
#include <QMessageBox>

Menu::Menu(QWidget *parent) :
    QTabWidget(parent)

{
    setCurrentWindow();
}

void Menu::setCurrentWindow()
{
    this->setFixedSize(500,500);
    this->setWindowTitle("Menu");
}

Menu::~Menu()
{
}

