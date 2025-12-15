#ifndef VENTANAHISTORIAL_H
#define VENTANAHISTORIAL_H

#include <QDialog> // O QMainWindow, depende de cómo lo creaste. QDialog es mejor para popups.
#include <string>
#include "backend/GestorBD.h" // AJUSTA ESTA RUTA SI ES NECESARIO

namespace Ui {
class VentanaHistorial;
}

class VentanaHistorial : public QDialog
{
    Q_OBJECT

public:
    explicit VentanaHistorial(QWidget *parent = nullptr);
    ~VentanaHistorial();

    // Función vital para saber de quién mostrar el historial
    void setRutUsuario(std::string rut);

private:
    Ui::VentanaHistorial *ui;
    std::string rutUsuario;

    void cargarDatos(); // Función interna para llenar la tabla
};

#endif // VENTANAHISTORIAL_H
