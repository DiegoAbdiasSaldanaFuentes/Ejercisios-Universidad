#ifndef VENTANAHISTORIAL_H
#define VENTANAHISTORIAL_H

#include <QDialog>

namespace Ui {
class VentanaHistorial;
}

class VentanaHistorial : public QDialog
{
    Q_OBJECT

public:
    explicit VentanaHistorial(QWidget *parent = nullptr);
    ~VentanaHistorial();


    void cargarDatos();

private slots:

    void on_btnEliminar_clicked();

private:
    Ui::VentanaHistorial *ui;
};

#endif
