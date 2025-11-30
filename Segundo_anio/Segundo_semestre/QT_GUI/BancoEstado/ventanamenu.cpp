#include "ventanamenu.h"
#include "ui_ventanamenu.h"
#include "loginwindow.h"
#include "ventanaoperacion.h"
#include "cliente.h"
#include "ventanahistorial.h"
#include <QMessageBox>
#include <QShowEvent>

VentanaMenu::VentanaMenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VentanaMenu)
{
    ui->setupUi(this);
    // LEER EL SALDO REAL DE LA CLASE CLIENTE
    int saldoReal = Cliente::getSaldo();

    // Convertir a texto y poner puntos (opcional)
    QString textoSaldo = "$ " + QString::number(saldoReal);

    // Pintarlo en la etiqueta (Asegúrate que tu etiqueta se llame lblSaldo)
    ui->lblSaldo->setText(textoSaldo);
}

VentanaMenu::~VentanaMenu(){
    delete ui;
}


void VentanaMenu::on_btnLogout_clicked(){
        // Instanciamos
        LoginWindow *login = new LoginWindow();

        //  Mostramos
        login->show();

        // Cerramos esta ventana de menú (Auto-destrucción)
        this->close();
}



void VentanaMenu::on_btnTransferir_clicked(){// Boton de transferir

    // Crear el menu otra vez
    ventanaoperacion *ventana = new ventanaoperacion();
    ventana->show();

    // Ocultar NO cerrar
    this->hide();
}


void VentanaMenu::on_btnHistorial_clicked()
{
    //  Crear la instancia de la ventana
    VentanaHistorial historial(this); // 'this' significa que depende del menú

    //  Hacerla MODAL (Bloquea la ventana de atrás hasta que cierre)
    historial.setModal(true);

    //  Ejecutarla
    historial.exec();
}

void VentanaMenu::on_btnDepositarTest_clicked()
{
    //  Instanciamos un cliente  para usar operadores
    Cliente miCliente;

    // USAMOS LA SOBRECARGA

    miCliente += 10000;//modificable

    // 3. Actualizamos la etiqueta visual
    ui->lblSaldo->setText("$ " + QString::number(Cliente::getSaldo()));

    QMessageBox::information(this, "Regalo", "Se han abonado $10.000 usando sobrecarga de operadores.");
}

void VentanaMenu::showEvent(QShowEvent *event)
{
    //  Llamamos a la función original
    QMainWindow::showEvent(event);

    //  AQUI ACTUALIZAMOS EL SALDO AUTOMÁTICAMENTE
    int saldoActualizado = Cliente::getSaldo();
    ui->lblSaldo->setText("$ " + QString::number(saldoActualizado));
}
