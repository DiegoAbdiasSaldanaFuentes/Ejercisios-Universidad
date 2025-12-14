#ifndef VENTANAOPERACION_H
#define VENTANAOPERACION_H

#include <QMainWindow>
#include <string>
#include "backend/GestorBD.h" // Importante

namespace Ui {
class ventanaoperacion; // Respetamos tu nombre en minúsculas
}

class ventanaoperacion : public QMainWindow
{
    Q_OBJECT

public:
    explicit ventanaoperacion(QWidget *parent = nullptr);
    ~ventanaoperacion();

    // Función para recibir identidad
    void setRutUsuario(std::string rut);

private slots:
    void on_btnVolver_clicked();
    void on_btnAccion_clicked(); // Este es tu botón de transferir

private:
    Ui::ventanaoperacion *ui;
    std::string rutUsuario; // Aquí guardamos quién opera
};

#endif // VENTANAOPERACION_H
