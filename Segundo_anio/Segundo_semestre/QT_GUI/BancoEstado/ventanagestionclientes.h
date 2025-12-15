#ifndef VENTANAGESTIONCLIENTES_H
#define VENTANAGESTIONCLIENTES_H

#include <QWidget>
#include "backend/GestorBD.h" // Asegura la ruta correcta
#include <QTableWidgetItem>

namespace Ui {
class ventanagestionclientes;
}

class ventanagestionclientes : public QWidget
{
    Q_OBJECT

public:
    explicit ventanagestionclientes(QWidget *parent = nullptr);
    ~ventanagestionclientes();

private slots:
    void on_btnAgregar_clicked();
    void on_btnEliminar_clicked();

    // --- NUEVOS SLOTS ---
    void on_btnModificar_clicked();      // Lógica para actualizar
    void on_btnCargar_clicked();         // Lógica para limpiar/refrescar
    void on_tablaClientes_cellClicked(int row, int column); // Lógica para llenar campos al tocar tabla

private:
    Ui::ventanagestionclientes *ui;
    void cargarDatosEnTabla();
};

#endif // VENTANAGESTIONCLIENTES_H
