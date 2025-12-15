#include "ventanagestionclientes.h"
#include "ui_ventanagestionclientes.h"
#include <QMessageBox>
#include <vector>

ventanagestionclientes::ventanagestionclientes(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ventanagestionclientes)
{
    ui->setupUi(this);

    // Configuración inicial de la tabla para que se vea bien
    ui->tablaClientes->setColumnCount(3);
    QStringList titulos;
    titulos << "RUT" << "Nombre" << "Password";
    ui->tablaClientes->setHorizontalHeaderLabels(titulos);
    ui->tablaClientes->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tablaClientes->setSelectionBehavior(QAbstractItemView::SelectRows); // Seleccionar fila completa
    ui->tablaClientes->setEditTriggers(QAbstractItemView::NoEditTriggers);  // No editar directo en tabla

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

// --- 1. FUNCIÓN CARGAR (AHORA SIRVE PARA LIMPIAR) ---
void ventanagestionclientes::on_btnCargar_clicked()
{
    // Limpiamos los campos para permitir agregar uno nuevo
    ui->txtRut->clear();
    ui->txtNombre->clear();
    ui->txtClave->clear();

    // Reactivamos el RUT por si estaba bloqueado
    ui->txtRut->setEnabled(true);

    // Recargamos la tabla por si hubo cambios externos
    cargarDatosEnTabla();
}

// --- 2. FUNCIÓN MÁGICA: LLENAR CAMPOS AL TOCAR TABLA ---
// (Debes ir al .ui, click derecho en la tabla -> Go to slot -> cellClicked)
void ventanagestionclientes::on_tablaClientes_cellClicked(int row, int column)
{
    // Obtenemos los datos de la fila seleccionada
    QString rut  = ui->tablaClientes->item(row, 0)->text();
    QString nombre = ui->tablaClientes->item(row, 1)->text();
    QString clave = ui->tablaClientes->item(row, 2)->text();

    // Los ponemos en las cajas de texto
    ui->txtRut->setText(rut);
    ui->txtNombre->setText(nombre);
    ui->txtClave->setText(clave);

    // OJO: Bloqueamos el RUT porque es la LLAVE PRIMARIA. No se debe editar el RUT.
    // Para cambiar un RUT, se borra el usuario y se crea otro.
    ui->txtRut->setEnabled(false);
}

// --- 3. FUNCIÓN MODIFICAR (LA QUE FALTABA) ---
void ventanagestionclientes::on_btnModificar_clicked()
{
    try {
        QString rut = ui->txtRut->text().trimmed();
        QString nombre = ui->txtNombre->text().trimmed();
        QString clave = ui->txtClave->text().trimmed();

        if (rut.isEmpty() || nombre.isEmpty() || clave.isEmpty()) {
            QMessageBox::warning(this, "Aviso", "Selecciona un usuario de la tabla primero.");
            return;
        }

        GestorBD gestor("banco.db");

        // Llamamos a la función de modificar (asegúrate que exista en GestorBD.cpp)
        gestor.modificarCliente(rut.toStdString(), nombre.toStdString(), clave.toStdString());

        QMessageBox::information(this, "Éxito", "Usuario modificado correctamente.");

        // Limpiamos todo
        on_btnCargar_clicked();

    } catch (exception &e) {
        QMessageBox::critical(this, "Error al modificar", e.what());
    }
}

void ventanagestionclientes::on_btnAgregar_clicked()
{
    try {
        QString rut = ui->txtRut->text().trimmed();
        QString nombre = ui->txtNombre->text().trimmed();
        QString clave = ui->txtClave->text().trimmed();

        if(rut.isEmpty() || nombre.isEmpty() || clave.isEmpty()){
            QMessageBox::warning(this, "Aviso", "Todos los campos son obligatorios.");
            return;
        }

        GestorBD gestor("banco.db");

        if (gestor.existeCliente(rut.toStdString())) {
            QMessageBox::warning(this, "Error", "El usuario ya existe. Use Modificar si desea cambiar datos.");
            return;
        }

        gestor.agregarCliente(rut.toStdString(), nombre.toStdString(), clave.toStdString());
        gestor.crearCuenta(rut.toStdString());

        QMessageBox::information(this, "Éxito", "Usuario creado correctamente.");

        on_btnCargar_clicked(); // Limpiamos y refrescamos

    } catch (std::exception &e) {
        QMessageBox::critical(this, "Error", e.what());
    }
}

void ventanagestionclientes::on_btnEliminar_clicked()
{
    // Validamos si hay algo seleccionado en la tabla O si hay un RUT escrito
    QString rut = ui->txtRut->text();

    if (rut.isEmpty()) {
        int fila = ui->tablaClientes->currentRow();
        if (fila >= 0) {
            rut = ui->tablaClientes->item(fila, 0)->text();
        } else {
            QMessageBox::warning(this, "Aviso", "Selecciona un usuario de la tabla o escribe su RUT.");
            return;
        }
    }

    QMessageBox::StandardButton respuesta;
    respuesta = QMessageBox::question(this, "Confirmar",
                                      "¿Eliminar usuario " + rut + "?",
                                      QMessageBox::Yes | QMessageBox::No);

    if (respuesta == QMessageBox::Yes) {
        try {
            GestorBD gestor("banco.db");
            gestor.eliminarCliente(rut.toStdString());
            QMessageBox::information(this, "Eliminado", "Cliente eliminado.");
            on_btnCargar_clicked(); // Limpiar y refrescar
        } catch (exception &e) {
            QMessageBox::critical(this, "Error", e.what());
        }
    }
}
