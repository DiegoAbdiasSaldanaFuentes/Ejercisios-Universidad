#ifndef VENTANAMENU_H
#define VENTANAMENU_H

#include <QMainWindow>

namespace Ui {
class VentanaMenu;
}

class VentanaMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaMenu(QWidget *parent = nullptr);
    ~VentanaMenu();

private:
    Ui::VentanaMenu *ui;
};

#endif // VENTANAMENU_H
