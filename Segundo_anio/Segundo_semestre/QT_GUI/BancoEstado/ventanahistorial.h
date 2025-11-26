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

    // --- ESTA FALTABA: Declaramos que existe la función cargarDatos ---
    void cargarDatos();

private slots:
    // --- ESTA FALTABA: Declaramos que existe el botón eliminar ---
    void on_btnEliminar_clicked();

private:
    Ui::VentanaHistorial *ui;
};

#endif // VENTANAHISTORIAL_H
