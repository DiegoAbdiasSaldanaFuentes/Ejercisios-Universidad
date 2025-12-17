#ifndef VENTANAMENU_H
#define VENTANAMENU_H

#include <QMainWindow>
#include <string>
#include "backend/GestorBD.h"
#include "ventanagestionclientes.h"

namespace Ui {
class VentanaMenu;
}

class VentanaMenu : public QMainWindow
{
    Q_OBJECT

protected:
    void showEvent(QShowEvent *event) override;

public:
    explicit VentanaMenu(QWidget *parent = nullptr);
    ~VentanaMenu();


    void setRutUsuario(std::string rut);

private slots:
    void on_btnLogout_clicked();
    void on_btnTransferir_clicked();
    void on_btnDepositarTest_clicked();
    void on_btnGestion_clicked();

private:
    Ui::VentanaMenu *ui;
    std::string rutUsuario;

    void actualizarSaldoVisual();
};

#endif
