#include "ventanagestionclientes.h"
#include "ui_ventanagestionclientes.h"
#include <QMessageBox>
#include <vector>

// Constructor con nombre en minúscula
ventanagestionclientes::ventanagestionclientes(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ventanagestionclientes)
{
    ui->setupUi(this);
    cargarDatosEnTabla();
}

ventanagestionclientes::~ventanagestionclientes()
{
    delete ui;
}

void ventanagestionclientes::cargarDatosEnTabla()
{
    try {
        GestorBD gestor("banco.db");
        // Usamos tu struct ClienteData
        vector<ClienteData> lista = gestor.obtenerTodosLosClientes();

        ui->tablaClientes->setRowCount(0);

        for (const ClienteData &cliente : lista) {
            int fila = ui->tablaClientes->rowCount();
            ui->tablaClientes->insertRow(fila);

            ui->tablaClientes->setItem(fila, 0, new QTableWidgetItem(QString::fromStdString(cliente.rut)));
            ui->tablaClientes->setItem(fila, 1, new QTableWidgetItem(QString::fromStdString(cliente.nombre)));
            ui->tablaClientes->setItem(fila, 2, new QTableWidgetItem(QString::fromStdString(cliente.password)));
        }
    } catch (exception &e) {
        QMessageBox::critical(this, "Error BD", e.what());
    }
}

void ventanagestionclientes::on_btnCargar_clicked()
{
    cargarDatosEnTabla();
}

void ventanagestionclientes::on_btnAgregar_clicked()
{
    try {
        // Asegúrate que en el diseño (.ui) los objetos se llamen así:
        QString rut = ui->txtRut->text().trimmed();
        QString nombre = ui->txtNombre->text().trimmed();
        QString clave = ui->txtClave->text().trimmed();

        if(rut.isEmpty() || nombre.isEmpty() || clave.isEmpty()){
            QMessageBox::warning(this, "Aviso", "Todos los campos son obligatorios.");
            return;
        }

        GestorBD gestor("banco.db");

        if (gestor.existeCliente(rut.toStdString())) {
            QMessageBox::warning(this, "Error", "El usuario ya existe.");
            return;
        }

        gestor.agregarCliente(rut.toStdString(), nombre.toStdString(), clave.toStdString());
        gestor.crearCuenta(rut.toStdString()); // Crea cuenta automáticamente

        QMessageBox::information(this, "Éxito", "Usuario creado correctamente.");

        ui->txtRut->clear();
        ui->txtNombre->clear();
        ui->txtClave->clear();
        cargarDatosEnTabla();

    } catch (std::exception &e) {
        QMessageBox::critical(this, "Error", e.what());
    }
}

void ventanagestionclientes::on_btnEliminar_clicked()
{
    int fila = ui->tablaClientes->currentRow();
    if (fila < 0) {
        QMessageBox::warning(this, "Aviso", "Selecciona un usuario de la tabla.");
        return;
    }

    QString rut = ui->tablaClientes->item(fila, 0)->text();

    QMessageBox::StandardButton respuesta;
    respuesta = QMessageBox::question(this, "Confirmar",
                                      "¿Eliminar usuario " + rut + "?",
                                      QMessageBox::Yes | QMessageBox::No);

    if (respuesta == QMessageBox::Yes) {
        try {
            GestorBD gestor("banco.db");
            gestor.eliminarCliente(rut.toStdString());
            cargarDatosEnTabla();
        } catch (exception &e) {
            QMessageBox::critical(this, "Error", e.what());
        }
    }
}
