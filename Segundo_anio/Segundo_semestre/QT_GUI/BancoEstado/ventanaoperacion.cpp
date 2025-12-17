#include "ventanaoperacion.h"
#include "ui_ventanaoperacion.h"
#include "ventanamenu.h"
#include "backend/GestorBD.h"
#include <QMessageBox>
#include <stdexcept>
#include <QIntValidator>

ventanaoperacion::ventanaoperacion(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ventanaoperacion)
{
    ui->setupUi(this);

    ui->txtMonto->setValidator(new QIntValidator(1, 99999999, this));
}

ventanaoperacion::~ventanaoperacion()
{
    delete ui;
}

void ventanaoperacion::setRutUsuario(std::string rut) {
    this->rutUsuario = rut;
}

void ventanaoperacion::on_btnVolver_clicked()
{
    VentanaMenu *menu = new VentanaMenu();
    menu->setRutUsuario(this->rutUsuario);
    menu->show();
    this->close();
}

void ventanaoperacion::on_btnAccion_clicked()
{
    try {

        QString textoMonto = ui->txtMonto->text();
        QString textoDestino = ui->txtDestino->text();

        if(textoMonto.isEmpty() || textoDestino.isEmpty())
            throw std::invalid_argument("Faltan datos.");

        bool esNumero;
        int monto = textoMonto.toInt(&esNumero);
        if (!esNumero || monto <= 0)
            throw std::invalid_argument("Monto inválido.");

        std::string rutDestino = textoDestino.toStdString();
        if (rutDestino == rutUsuario)
            throw std::invalid_argument("No puedes transferirte a ti mismo.");


        GestorBD gestor("banco.db");

        // Validar saldos y existencia
        int miId = gestor.obtenerIdCuentaPorRut(rutUsuario);
        if (miId == -1) throw std::runtime_error("Tu usuario no tiene cuenta activa.");

        double miSaldo = gestor.obtenerSaldo(miId);
        if (monto > miSaldo) throw std::runtime_error("Saldo insuficiente.");

        int idDestino = gestor.obtenerIdCuentaPorRut(rutDestino);
        if (idDestino == -1) throw std::runtime_error("El destinatario no existe.");


        gestor.actualizarSaldo(miId, miSaldo - monto);
        gestor.actualizarSaldo(idDestino, gestor.obtenerSaldo(idDestino) + monto);


        gestor.registrarMovimiento("Transferencia", rutUsuario, rutDestino, (double)monto);

        QMessageBox::information(this, "Éxito", "Transferencia realizada y guardada.");

        on_btnVolver_clicked();

    } catch (const std::exception &e) {
        QMessageBox::warning(this, "Error", e.what());
    }
}
