#include "ventanamenu.h"
#include "ui_ventanamenu.h"
#include "loginwindow.h"
#include "ventanaoperacion.h"
#include "cliente.h"
#include "ventanahistorial.h"

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
    // 1. Crear la instancia de la ventana
    VentanaHistorial historial(this); // 'this' significa que depende del menú

    // 2. Hacerla MODAL (Bloquea la ventana de atrás hasta que cierres esta)
    historial.setModal(true);

    // 3. Ejecutarla
    historial.exec();
}
