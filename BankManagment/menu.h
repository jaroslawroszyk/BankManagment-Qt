#pragma once
#include <QTabWidget>

namespace Ui
{
class Menu;
}

class Menu : public QTabWidget
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parrent = nullptr);
    ~Menu();
private:
    Ui::Menu *ui;
};
