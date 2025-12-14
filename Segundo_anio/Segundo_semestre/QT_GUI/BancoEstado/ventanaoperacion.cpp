#include "ventanaoperacion.h"
#include "ui_ventanaoperacion.h"
#include "ventanamenu.h"
#include <QMessageBox>
#include <stdexcept>
#include <QIntValidator>

ventanaoperacion::ventanaoperacion(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ventanaoperacion)
{
    ui->setupUi(this);
    // Solo números en el campo de monto
    ui->txtMonto->setValidator(new QIntValidator(0, 99999999, this));
}

ventanaoperacion::~ventanaoperacion()
{
    delete ui;
}

void ventanaoperacion::setRutUsuario(std::string rut) {
    this->rutUsuario = rut;
    // Opcional: Podrías poner el rut en algún label para saber quién eres
}

void ventanaoperacion::on_btnVolver_clicked()
{
    // Al volver, creamos el menú de nuevo
    VentanaMenu *menu = new VentanaMenu();

    // --- NO OLVIDAR: Devolverle el RUT al menú ---
    menu->setRutUsuario(this->rutUsuario);

    menu->show();
    this->close();
}
void ventanaoperacion::on_btnAccion_clicked()
{
    try {
        // 1. Capturar datos
        QString textoMonto = ui->txtMonto->text();
        QString textoDestino = ui->txtDestino->text();

        if(textoMonto.isEmpty() || textoDestino.isEmpty()) {
            throw std::invalid_argument("Faltan datos. Rellene todo.");
        }

        // Conversión y validación de monto
        bool esNumero;
        int monto = textoMonto.toInt(&esNumero);

        if (!esNumero || monto <= 0) {
            throw std::invalid_argument("El monto debe ser un número positivo.");
        }

        std::string rutDestino = textoDestino.toStdString();

        // Evitar auto-transferencia
        if (rutDestino == rutUsuario) {
            throw std::invalid_argument("No puedes transferirte a ti mismo.");
        }

        // 2. CONEXIÓN CON LA BASE DE DATOS
        GestorBD gestor("banco.db");

        // A. Obtener mis datos (Origen)
        int miId = gestor.obtenerIdCuentaPorRut(rutUsuario);
        if (miId == -1) throw std::runtime_error("Error: Tu usuario no tiene cuenta activa.");

        double miSaldo = gestor.obtenerSaldo(miId);

        // B. Obtener datos destino
        int idDestino = gestor.obtenerIdCuentaPorRut(rutDestino);
        if (idDestino == -1) throw std::runtime_error("El RUT de destino no existe en el banco.");

        // C. Verificar fondos
        if (monto > miSaldo) {
            throw std::runtime_error("Saldo insuficiente en la cuenta.");
        }

        // 3. EJECUTAR LA TRANSACCIÓN (Backend)
        double nuevoSaldoMio = miSaldo - monto;
        double nuevoSaldoDestino = gestor.obtenerSaldo(idDestino) + monto;

        gestor.actualizarSaldo(miId, nuevoSaldoMio);
        gestor.actualizarSaldo(idDestino, nuevoSaldoDestino);

        // --- ¡AQUÍ ESTÁ LO NUEVO! GUARDAMOS EL RECIBO ---
        // (Tipo, Origen, Destino, Monto)
        gestor.registrarMovimiento("Transferencia", rutUsuario, rutDestino, (double)monto);

        // 4. Feedback
        QMessageBox::information(this, "Éxito", "Transferencia realizada correctamente.");

        // Limpiar
        ui->txtMonto->clear();
        ui->txtDestino->clear();

        // Volver al menú automáticamente
        on_btnVolver_clicked();

    } catch (const std::exception &e) {
        QMessageBox::warning(this, "Error", e.what());
    }
}
