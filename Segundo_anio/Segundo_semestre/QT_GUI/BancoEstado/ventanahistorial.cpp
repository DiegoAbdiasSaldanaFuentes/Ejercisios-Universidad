#include "ventanahistorial.h"
#include "ui_ventanahistorial.h"
#include "cliente.h" // <--- Vital para leer los datos
#include <QMessageBox>
#include <QHeaderView> // <--- Para que las columnas se estiren

VentanaHistorial::VentanaHistorial(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VentanaHistorial)
{
    ui->setupUi(this);

    // 1. CONFIGURACIÓN VISUAL DE LA TABLA
    // Le decimos que tendrá 3 columnas
    ui->tblHistorial->setColumnCount(3);

    // Ponemos los títulos
    QStringList titulos;
    titulos << "RUT Destino" << "Banco" << "Monto";
    ui->tblHistorial->setHorizontalHeaderLabels(titulos);

    // Hacemos que se estiren para ocupar todo el ancho
    ui->tblHistorial->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // 2. CARGAR LOS DATOS INMEDIATAMENTE
    cargarDatos();
}

VentanaHistorial::~VentanaHistorial()
{
    delete ui;
}

void VentanaHistorial::cargarDatos()
{
    // A. Limpiamos la tabla para empezar de cero
    ui->tblHistorial->setRowCount(0);

    // B. Traemos la lista de la memoria
    QList<Movimiento> lista = Cliente::getMovimientos();

    // C. Recorremos la lista y creamos las filas
    for(int i = 0; i < lista.size(); i++) {
        ui->tblHistorial->insertRow(i); // Crear fila vacía

        // Llenamos las celdas
        ui->tblHistorial->setItem(i, 0, new QTableWidgetItem(lista[i].rut));
        ui->tblHistorial->setItem(i, 1, new QTableWidgetItem(lista[i].banco));
        ui->tblHistorial->setItem(i, 2, new QTableWidgetItem(QString::number(lista[i].monto)));
    }
}

void VentanaHistorial::on_btnEliminar_clicked(){
    // Ver qué fila seleccionó el usuario
    int fila = ui->tblHistorial->currentRow();

    if (fila < 0) {
        QMessageBox::warning(this, "Aviso", "Seleccione una fila para borrar.");
        return;
    }

}  // Borrar de la memoria y actualizar la tabla
