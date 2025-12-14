#include "backend/GestorBD.h"
#include "loginwindow.h"
#include "ui_loginwindow.h" // A veces es "./ui_loginwindow.h" dependiendo de la versión
#include <QMessageBox>
#include "ventanamenu.h"
#include <QRegularExpression>
#include <stdexcept>

// --- 1. CONSTRUCTOR (¡ESTO FALTABA!) ---
// Aquí es donde se "nace" la ventana y se configuran los elementos visuales
LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

// --- 2. DESTRUCTOR (¡ESTO TAMBIÉN FALTABA!) ---
// Aquí se limpia la memoria cuando cierras la ventana
LoginWindow::~LoginWindow()
{
    delete ui;
}

// --- 3. TU LÓGICA DEL BOTÓN ---
void LoginWindow::on_btnIngresar_clicked()
{
    try {
        QString rut = ui->txtRut->text().trimmed();
        QString clave = ui->txtClave->text().trimmed();

        // 1. Validar formato RUT
        QRegularExpression regexRut("^[0-9]+-[0-9kK]$");
        if (!regexRut.match(rut).hasMatch()) {
            throw std::invalid_argument("El RUT debe tener formato: 12345678-9");
        }

        GestorBD gestor("banco.db");
        std::string rutStd = rut.toStdString();
        std::string claveStd = clave.toStdString();

        // 2. PREGUNTAR: ¿Existe el usuario y la clave es correcta?
        if (gestor.validarCliente(rutStd, claveStd)) {

            // --- AQUÍ ESTÁ EL ARREGLO ("LA REPARACIÓN") ---
            // Ya sabemos que eres usuario, ahora vemos si tienes cuenta bancaria
            int idCuenta = gestor.obtenerIdCuentaPorRut(rutStd);

            if (idCuenta == -1) {
                // Eres un usuario "Zombie" (sin cuenta). ¡Te arreglamos ahora!
                gestor.crearCuenta(rutStd);

                // Buscamos tu nueva cuenta y le regalamos saldo inicial
                idCuenta = gestor.obtenerIdCuentaPorRut(rutStd);
                gestor.actualizarSaldo(idCuenta, 500000);

                QMessageBox::information(this, "Cuenta Creada", "Tu usuario no tenía cuenta activa. Se ha creado una nueva con $500.000 de regalo.");
            }
            // -----------------------------------------------

            QMessageBox::information(this, "Éxito", "¡Bienvenido al Banco!", QMessageBox::Ok);

            // Abrir el menú pasándole tu RUT
            VentanaMenu *menu = new VentanaMenu();
            menu->setRutUsuario(rutStd);
            menu->show();
            this->close();
        }
        else {
            throw std::runtime_error("RUT o Clave incorrectos.");
        }

    }
    catch (const std::exception &e) {
        QMessageBox::warning(this, "Error", e.what());
    }
}
