#include "ventanahistorial.h"
#include "ui_ventanahistorial.h"
#include <QMessageBox> // Necesario para mensajes de error

VentanaHistorial::VentanaHistorial(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VentanaHistorial)
{
    ui->setupUi(this);

    // BLINDAJE 1: Verificar que la tabla exista antes de tocarla
    if (ui->tblHistorial == nullptr) {
        QMessageBox::critical(this, "Error Fatal", "La tabla 'tblHistorial' no existe en el diseño .ui");
        return;
    }

    ui->tblHistorial->setColumnCount(4);
    QStringList titulos;
    titulos << "Tipo" << "Origen" << "Destino" << "Monto";
    ui->tblHistorial->setHorizontalHeaderLabels(titulos);

    // Ajuste visual
    ui->tblHistorial->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

VentanaHistorial::~VentanaHistorial()
{
    delete ui;
}

void VentanaHistorial::setRutUsuario(std::string rut) {
    // BLINDAJE 2: Si el RUT llega vacío, avisar (útil para debugging)
    if (rut.empty()) {
        QMessageBox::warning(this, "Advertencia", "No se recibió el RUT del usuario.");
        return;
    }

    this->rutUsuario = rut;
    cargarDatos();
}
void VentanaHistorial::cargarDatos()
{
    // Limpiamos la tabla primero
    ui->tblHistorial->setRowCount(0);

    try {
        // "try" significa: "Intenta hacer esto, y si explota, atrápalo"
        GestorBD gestor("banco.db");

        vector<Movimiento> lista = gestor.obtenerHistorial(rutUsuario);

        for(size_t i = 0; i < lista.size(); i++) {
            ui->tblHistorial->insertRow(i);

            // Convertimos std::string a QString de forma segura
            ui->tblHistorial->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(lista[i].tipo)));
            ui->tblHistorial->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(lista[i].rutOrigen)));
            ui->tblHistorial->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(lista[i].rutDestino)));
            ui->tblHistorial->setItem(i, 3, new QTableWidgetItem(QString::number(lista[i].monto)));
        }
    }
    catch (std::exception &e) {
        // Si ocurre un error, NO cerramos. Mostramos mensaje.
        QMessageBox::critical(this, "Error de Historial", "No se pudo leer la base de datos: " + QString(e.what()));
    }
}

void VentanaHistorial::on_btnEliminar_clicked()
{
    // Botón sin acción por seguridad
}
