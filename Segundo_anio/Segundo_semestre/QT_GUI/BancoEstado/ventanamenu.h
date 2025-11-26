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

private slots:
    void on_btnLogout_clicked();

    void on_btnTransferir_clicked();

    void on_btnHistorial_clicked();

private:
    Ui::VentanaMenu *ui;
};

#endif // VENTANAMENU_H
