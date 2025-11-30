#include "ventanaoperacion.h"
#include "ui_ventanaoperacion.h"
#include "ventanamenu.h"
#include "cliente.h"
#include <QMessageBox>
#include <stdexcept>
#include <QIntValidator>

ventanaoperacion::ventanaoperacion(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ventanaoperacion)
{
    ui->setupUi(this);
    ui->txtMonto->setValidator(new QIntValidator(0, 99999999, this));

}

ventanaoperacion::~ventanaoperacion()
{
    delete ui;
}

void ventanaoperacion::on_btnVolver_clicked()// Boton volver
{
    VentanaMenu *menu = new VentanaMenu();

    // Crear la ventana
    menu->show();
    // Cerrar la ventana
    this->close();
}


void ventanaoperacion::on_btnAccion_clicked()
{
    try {
        // Capturar datos
        QString textoMonto = ui->txtMonto->text();
        QString textoDestino = ui->txtDestino->text();

        // Validación de vacíos
        if(textoMonto.isEmpty() || textoDestino.isEmpty()) {
            throw std::invalid_argument("Faltan datos. Rellene todo.");
        }

        // CONVERSIÓN SEGURA
        bool esNumero;
        int monto = textoMonto.toInt(&esNumero); // &esNumero se vuelve FALSE si hay letras

        // Aquí atrapamos "hola", "hol0@", "10a", "###".
        if (esNumero == false) {
            throw std::invalid_argument("El monto no es válido (contiene letras o símbolos).");
        }

        //  Validaciones Lógicas
        if (monto <= 0) {
            throw std::domain_error("El monto debe ser mayor a cero.");
        }

        //  Validación de Saldo
        int saldoActual = Cliente::getSaldo();
        if (monto > saldoActual) {
            throw std::runtime_error("Saldo insuficiente.");
        }


        Cliente::disminuirSaldo(monto);
        QString bancoSeleccionado = ui->cmbBanco->currentText();
        Cliente::agregarMovimiento(textoDestino, bancoSeleccionado, monto);

        QMessageBox::information(this, "Éxito", "Transferencia realizada.");

        ui->txtMonto->clear();
        ui->txtDestino->clear();

    } catch (const std::exception &e) {
        QMessageBox::warning(this, "Error", e.what());
    }
}
