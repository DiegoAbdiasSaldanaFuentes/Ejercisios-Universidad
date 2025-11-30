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

    // 1. Configuración de Columnas
    ui->tblHistorial->setColumnCount(3);
    QStringList titulos;
    titulos << "RUT Destino" << "Banco" << "Monto";
    ui->tblHistorial->setHorizontalHeaderLabels(titulos);
    ui->tblHistorial->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // --- AGREGA ESTAS LÍNEAS DE SEGURIDAD ---

    // A. Bloquear edición: Nadie puede escribir en las celdas
    ui->tblHistorial->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // B. Selección de fila completa: Se ve más profesional (Opcional pero recomendado)
    // Al hacer clic, se selecciona toda la fila azul, no solo una celda
    ui->tblHistorial->setSelectionBehavior(QAbstractItemView::SelectRows);

    // C. Selección única: Solo puedes borrar de a uno (Evita errores de lógica)
    ui->tblHistorial->setSelectionMode(QAbstractItemView::SingleSelection);

    // ----------------------------------------

    // 2. Cargar datos
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

void VentanaHistorial::on_btnEliminar_clicked()
{
    // 1. Obtener la fila seleccionada visualmente
    // currentRow() devuelve el número de fila (0, 1, 2...) o -1 si no hay nada seleccionado.
    int filaSeleccionada = ui->tblHistorial->currentRow();

    // 2. Validación de Usuario (UX)
    if (filaSeleccionada == -1) {
        QMessageBox::warning(this, "Atención", "Por favor, selecciona una fila para eliminar.");
        return; // Detenemos la función aquí
    }

    // 3. Confirmación (Buenas prácticas de interfaz)
    // Es peligroso borrar sin preguntar. Esto suma puntos de diseño.
    QMessageBox::StandardButton respuesta;
    respuesta = QMessageBox::question(this, "Confirmar",
                                      "¿Estás seguro de que deseas eliminar este registro?",
                                      QMessageBox::Yes | QMessageBox::No);

    if (respuesta == QMessageBox::Yes) {

        // 4. Borrar del Backend (Memoria / Futura Base de Datos)
        Cliente::eliminarMovimiento(filaSeleccionada);

        // 5. Refrescar la tabla (Para que desaparezca visualmente)
        cargarDatos();

        QMessageBox::information(this, "Éxito", "Registro eliminado correctamente.");
    }
}
