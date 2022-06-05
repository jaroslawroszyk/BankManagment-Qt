#pragma once
#include "WindowsOptions.h"
#include <QTabWidget>

namespace Ui
{
class Menu;
}

class Menu : public QTabWidget, public WindowsOptions
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parrent = nullptr);
    ~Menu();
private:
    Ui::Menu *ui;
    void setCurrentWindow() override;
};
