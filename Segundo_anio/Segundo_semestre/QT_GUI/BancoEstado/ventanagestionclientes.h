#ifndef VENTANAGESTIONCLIENTES_H
#define VENTANAGESTIONCLIENTES_H

#include <QWidget>
#include "backend/GestorBD.h"
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


    void on_btnModificar_clicked();
    void on_btnCargar_clicked();
    void on_tablaClientes_cellClicked(int row, int column);

private:
    Ui::ventanagestionclientes *ui;
    void cargarDatosEnTabla();
};

#endif
