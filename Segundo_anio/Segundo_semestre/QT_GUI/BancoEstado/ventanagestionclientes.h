#ifndef VENTANAGESTIONCLIENTES_H
#define VENTANAGESTIONCLIENTES_H

#include <QWidget>
#include "backend/GestorBD.h"
#include <QTableWidgetItem>

namespace Ui {
class ventanagestionclientes; // <--- Aquí estaba el error, ahora es minúscula
}

class ventanagestionclientes : public QWidget // <--- Clase en minúscula
{
    Q_OBJECT

public:
    explicit ventanagestionclientes(QWidget *parent = nullptr);
    ~ventanagestionclientes();

private slots:
    void on_btnAgregar_clicked();
    void on_btnEliminar_clicked();
    void on_btnCargar_clicked();

private:
    Ui::ventanagestionclientes *ui; // <--- Puntero en minúscula
    void cargarDatosEnTabla();
};

#endif // VENTANAGESTIONCLIENTES_H
