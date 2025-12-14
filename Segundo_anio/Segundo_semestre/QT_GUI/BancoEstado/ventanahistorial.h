#ifndef VENTANAHISTORIAL_H
#define VENTANAHISTORIAL_H

#include <QDialog>
#include <string>
#include "backend/GestorBD.h" // <--- CAMBIO IMPORTANTE

namespace Ui {
class VentanaHistorial;
}

class VentanaHistorial : public QDialog
{
    Q_OBJECT

public:
    explicit VentanaHistorial(QWidget *parent = nullptr);
    ~VentanaHistorial();

    // Nueva función vital: Para saber DE QUIÉN mostramos el historial
    void setRutUsuario(std::string rut);

    void cargarDatos();

private slots:
    void on_btnEliminar_clicked();

private:
    Ui::VentanaHistorial *ui;
    std::string rutUsuario; // Variable para recordar el RUT
};

#endif // VENTANAHISTORIAL_H
