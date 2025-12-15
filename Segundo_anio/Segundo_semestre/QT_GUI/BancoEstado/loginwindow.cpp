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
        // OJO: Usamos txtClave porque así está en tu código pegado
        QString clave = ui->txtClave->text().trimmed();

        // 1. Validar formato RUT
        QRegularExpression regexRut("^[0-9]+-[0-9kK]$");
        if (!regexRut.match(rut).hasMatch()) {
            throw std::invalid_argument("El RUT debe tener formato: 12345678-9");
        }

        std::string rutStd = rut.toStdString();
        std::string claveStd = clave.toStdString();

        // Bloque para limitar la vida del GestorBD
        {
            GestorBD gestor("banco.db");

            // 2. Validar credenciales
            if (!gestor.validarCliente(rutStd, claveStd)) {
                throw std::runtime_error("RUT o Clave incorrectos.");
            }

            // 3. Verificar si el usuario tiene cuenta creada
            int idCuenta = gestor.obtenerIdCuentaPorRut(rutStd);
            if (idCuenta == -1) {
                // Usuario sin cuenta -> Crear cuenta y regalar saldo
                gestor.crearCuenta(rutStd);
                idCuenta = gestor.obtenerIdCuentaPorRut(rutStd);
                gestor.actualizarSaldo(idCuenta, 500000);
                QMessageBox::information(this, "Bienvenida", "Cuenta activada con bono de $500.000.");
            }

            // --- [AQUÍ INSERTAMOS LA PRUEBA PARA EL PROFE] ---
            // Esto solo saldrá en la consola "Application Output" de Qt Creator

            // A. Prueba Sobrecarga de Método (Pedimos saldo usando RUT string, no ID int)
            double saldoTest = gestor.obtenerSaldo(rutStd);
            qDebug() << "[PRUEBA SOBRECARGA METODO] Saldo de" << rut << "es: $" << saldoTest;

            // B. Prueba Sobrecarga de Operador (Imprimimos un struct directo con <<)
            Movimiento movTest = {"TestTecnico", "Origen", "Destino", 12345, "Hoy"};
            qDebug() << "[PRUEBA SOBRECARGA OPERADOR] " << movTest;

            // ------------------------------------------------

        } // <--- AQUÍ MUERE EL GESTOR (Se cierra la conexión)

        QMessageBox::information(this, "Éxito", "¡Bienvenido al Banco!", QMessageBox::Ok);

        // 4. Abrir el menú
        VentanaMenu *menu = new VentanaMenu();
        menu->setRutUsuario(rutStd);
        menu->show();

        this->close(); // Cerrar Login
    }
    catch (const std::exception &e) {
        QMessageBox::warning(this, "Error de Ingreso", e.what());
    }
}
