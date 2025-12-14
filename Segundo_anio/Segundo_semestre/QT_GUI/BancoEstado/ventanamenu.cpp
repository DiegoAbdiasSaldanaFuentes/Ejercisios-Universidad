#include "ventanamenu.h"
#include "ui_ventanamenu.h"
#include "loginwindow.h"
#include "ventanaoperacion.h"
#include "ventanahistorial.h" // Si no usas historial aun, comenta esto
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

// --- RECIBIR EL RUT DEL LOGIN ---
void VentanaMenu::setRutUsuario(std::string rut) {
    this->rutUsuario = rut;
    actualizarSaldoVisual(); // Apenas sabemos quién es, mostramos su saldo
}

// --- CONSULTAR BD Y MOSTRAR SALDO ---
void VentanaMenu::actualizarSaldoVisual() {
    try {
        GestorBD gestor("banco.db");
        // Buscamos la cuenta del usuario actual
        int idCuenta = gestor.obtenerIdCuentaPorRut(rutUsuario);

        if (idCuenta != -1) {
            double saldo = gestor.obtenerSaldo(idCuenta);
            ui->lblSaldo->setText("$ " + QString::number(saldo));
        } else {
            ui->lblSaldo->setText("$ 0 (Sin Cuenta)");
        }
    } catch (...) {
        ui->lblSaldo->setText("Error BD");
    }
}

void VentanaMenu::showEvent(QShowEvent *event)
{
    QMainWindow::showEvent(event);
    // Cada vez que la ventana aparece, refrescamos el dinero
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
    // Crear la ventana de operación
    ventanaoperacion *ventana = new ventanaoperacion();

    // --- PASO CRUCIAL: LE PASAMOS EL RUT ---
    ventana->setRutUsuario(this->rutUsuario);

    ventana->show();
    this->close(); // Cerramos el menú para no tener ventanas duplicadas
}
// En ventanamenu.cpp (Asegúrate de incluir "ventanahistorial.h" arriba)

void VentanaMenu::on_btnHistorial_clicked()
{
    // 1. Crear la ventana
    VentanaHistorial *ventana = new VentanaHistorial(this);

    // 2. IMPORTANTE: Pasarle el RUT (Si no, saldrá vacía)
    ventana->setRutUsuario(this->rutUsuario);

    // 3. Mostrarla
    ventana->exec(); // Usamos exec() porque es un QDialog (ventana modal)
}

void VentanaMenu::on_btnDepositarTest_clicked()
{
    try {
        GestorBD gestor("banco.db");

        // 1. Buscar mi cuenta
        int idCuenta = gestor.obtenerIdCuentaPorRut(this->rutUsuario);

        if (idCuenta == -1) {
            throw std::runtime_error("Error crítico: Usuario sin cuenta bancaria.");
        }

        // 2. Leer saldo actual de la BD
        double saldoActual = gestor.obtenerSaldo(idCuenta);

        // 3. Sumar dinero
        double nuevoSaldo = saldoActual + 10000;

        // 4. Guardar en BD
        gestor.actualizarSaldo(idCuenta, nuevoSaldo);

        // 5. Refrescar pantalla
        actualizarSaldoVisual();

        QMessageBox::information(this, "Regalo", "Se depositaron $10.000 en la Base de Datos.");

    } catch (const std::exception &e) {
        QMessageBox::warning(this, "Error", e.what());
    }
}



void VentanaMenu::on_btnGestion_clicked()
{
    // Crear y mostrar la ventana de gestión
    ventanagestionclientes *ventana = new ventanagestionclientes();
    ventana->show();
}

