#include "ventanamenu.h"
#include "ui_ventanamenu.h"
#include "GestorBD.h"
#include "loginwindow.h"
#include "ventanaoperacion.h"
#include "ventanagestionclientes.h"
#include <QMessageBox>
#include <QShowEvent>

VentanaMenu::VentanaMenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VentanaMenu)
{
    ui->setupUi(this);
}

VentanaMenu::~VentanaMenu(){
    delete ui;
}

void VentanaMenu::setRutUsuario(std::string rut) {
    this->rutUsuario = rut;

    // --- NUEVO CÓDIGO DE PERSONALIZACIÓN ---
    try {
        GestorBD gestor("banco.db");
        string nombreReal = gestor.obtenerNombreCliente(rut);

        // Ajusta 'labelBienvenida' al nombre real de tu etiqueta en el diseño
        ui->labelBienvenida->setText("Bienvenido, " + QString::fromStdString(nombreReal));

    } catch (...) {
        // Si falla, al menos mostramos el RUT
        ui->labelBienvenida->setText("Bienvenido " + QString::fromStdString(rut));
    }
    // ---------------------------------------

    actualizarSaldoVisual();
}

void VentanaMenu::actualizarSaldoVisual() {
    try {
        GestorBD gestor("banco.db");
        int idCuenta = gestor.obtenerIdCuentaPorRut(rutUsuario);

        if (idCuenta != -1) {
            double saldo = gestor.obtenerSaldo(idCuenta);
            ui->lblSaldo->setText("$ " + QString::number(saldo));
        } else {
            ui->lblSaldo->setText("$ 0 (Sin Cuenta)");
        }
    } catch (const std::exception &e) {
        ui->lblSaldo->setText("Error");
        // No lanzamos MessageBox aquí para no spammear al usuario cada vez que se abre la ventana
        qDebug() << "Error actualizando saldo: " << e.what();
    }
}

void VentanaMenu::showEvent(QShowEvent *event)
{
    QMainWindow::showEvent(event);
    if (!rutUsuario.empty()) {
        actualizarSaldoVisual();
    }
}

void VentanaMenu::on_btnLogout_clicked(){
    LoginWindow *login = new LoginWindow();
    login->show();
    this->close();
}

void VentanaMenu::on_btnTransferir_clicked(){
    ventanaoperacion *ventana = new ventanaoperacion();
    ventana->setRutUsuario(this->rutUsuario);
    ventana->show();
    this->close();
}



void VentanaMenu::on_btnDepositarTest_clicked()
{
    try {
        GestorBD gestor("banco.db");
        int idCuenta = gestor.obtenerIdCuentaPorRut(this->rutUsuario);

        if (idCuenta == -1) throw std::runtime_error("Usuario sin cuenta.");

        double saldoActual = gestor.obtenerSaldo(idCuenta);
        gestor.actualizarSaldo(idCuenta, saldoActual + 10000);

        // Registrar movimiento 'ficticio' de deposito
        gestor.registrarMovimiento("Deposito (Test)", "Cajero", this->rutUsuario, 10000);

        actualizarSaldoVisual();
        QMessageBox::information(this, "Regalo", "Se depositaron $10.000 + Registro en Historial.");

    } catch (const std::exception &e) {
        QMessageBox::warning(this, "Error", e.what());
    }
}

void VentanaMenu::on_btnGestion_clicked()
{
    ventanagestionclientes *ventana = new ventanagestionclientes();
    ventana->show();
}
