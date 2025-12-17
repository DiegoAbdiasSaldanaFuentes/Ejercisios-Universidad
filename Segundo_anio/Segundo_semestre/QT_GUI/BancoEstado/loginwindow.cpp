#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "GestorBD.h"       // AJUSTA ESTO SI TIENES CARPETAS
#include "ventanamenu.h"
#include <QMessageBox>
#include <QRegularExpression>
#include <stdexcept>

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}
void LoginWindow::on_btnIngresar_clicked()
{
    try {
        QString rut = ui->txtRut->text().trimmed();

        QString clave = ui->txtClave->text().trimmed();


        QRegularExpression regexRut("^[0-9]+-[0-9kK]$");
        if (!regexRut.match(rut).hasMatch()) {
            throw std::invalid_argument("El RUT debe tener formato: 12345678-9");
        }

        std::string rutStd = rut.toStdString();
        std::string claveStd = clave.toStdString();

        {
            GestorBD gestor("banco.db");


            if (!gestor.validarCliente(rutStd, claveStd)) {
                throw std::runtime_error("RUT o Clave incorrectos.");
            }


            int idCuenta = gestor.obtenerIdCuentaPorRut(rutStd);
            if (idCuenta == -1) {

                gestor.crearCuenta(rutStd);
                idCuenta = gestor.obtenerIdCuentaPorRut(rutStd);
                gestor.actualizarSaldo(idCuenta, 500000);
                QMessageBox::information(this, "Bienvenida", "Cuenta activada con bono de $500.000.");
            }


            double saldoTest = gestor.obtenerSaldo(rutStd);
            qDebug() << "[PRUEBA SOBRECARGA METODO] Saldo de" << rut << "es: $" << saldoTest;

            Movimiento movTest = {"TestTecnico", "Origen", "Destino", 12345, "Hoy"};
            qDebug() << "[PRUEBA SOBRECARGA OPERADOR] " << movTest;



        }

        QMessageBox::information(this, "Éxito", "¡Bienvenido al Banco!", QMessageBox::Ok);

        VentanaMenu *menu = new VentanaMenu();
        menu->setRutUsuario(rutStd);
        menu->show();

        this->close();
    }
    catch (const std::exception &e) {
        QMessageBox::warning(this, "Error de Ingreso", e.what());
    }
}
