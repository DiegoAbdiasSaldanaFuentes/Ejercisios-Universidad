#include "ventanamenu.h"
#include "ui_ventanamenu.h"

VentanaMenu::VentanaMenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VentanaMenu)
{
    ui->setupUi(this);
}

VentanaMenu::~VentanaMenu()
{
    delete ui;
}
