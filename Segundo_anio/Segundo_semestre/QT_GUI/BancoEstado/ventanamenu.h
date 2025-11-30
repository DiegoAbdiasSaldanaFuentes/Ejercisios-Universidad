#ifndef VENTANAMENU_H
#define VENTANAMENU_H

#include <QMainWindow>

namespace Ui {
class VentanaMenu;
}

class VentanaMenu : public QMainWindow
{
    Q_OBJECT

protected:
    // Sobreescribimos el evento de "Mostrar Ventana"
    void showEvent(QShowEvent *event) override;

public:
    explicit VentanaMenu(QWidget *parent = nullptr);
    ~VentanaMenu();

private slots:
    void on_btnLogout_clicked();

    void on_btnTransferir_clicked();

    void on_btnHistorial_clicked();

    void on_btnDepositarTest_clicked();

private:
    Ui::VentanaMenu *ui;
};

#endif // VENTANAMENU_H
