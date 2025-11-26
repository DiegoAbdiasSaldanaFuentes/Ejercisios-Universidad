#include "ventanaoperacion.h"
#include "ui_ventanaoperacion.h"
#include "ventanamenu.h" // Volver al menu de transeferencia
#include "cliente.h"
#include <QMessageBox>

ventanaoperacion::ventanaoperacion(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ventanaoperacion)
{
    ui->setupUi(this);
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
    // Llamamos el contenido que tendra txtMonto
    QString textoMonto = ui->txtMonto->text();

    // Transformamos  a INT
    int monto = textoMonto.toInt();

    // Preguntar cuánta plata hay
    int saldoActual = Cliente::getSaldo();

    if (monto > saldoActual) {
        QMessageBox::critical(this, "Saldo Insuficiente", "No tienes fondos.");
        return;
    }

    // RESTAMOS EL DINERO
    Cliente::disminuirSaldo(monto);

    //  Mensaje de éxito
    QMessageBox::information(this, "Éxito", "Transferencia realizada. Nuevo saldo: " + QString::number(Cliente::getSaldo()));

    // ... (código de la resta de saldo) ...

    // --- ESTO ES LO QUE GUARDA EL DATO EN LA LISTA ---
    QString bancoSeleccionado = ui->cmbBanco->currentText();
    QString rutDestino = ui->txtDestino->text();

    // Llamamos al método estático que creamos en Cliente
    Cliente::agregarMovimiento(rutDestino, bancoSeleccionado, monto);
    // -------------------------------------------------

}

