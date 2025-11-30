#include "loginwindow.h"
#include "./ui_loginwindow.h"
#include <QMessageBox>
#include "ventanamenu.h"
#include <QRegularExpression>
#include <stdexcept>

LoginWindow::LoginWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::LoginWindow){
    ui->setupUi(this);

}

LoginWindow::~LoginWindow(){
    delete ui;
}

void LoginWindow::on_btnIngresar_clicked()
{
    try {
        QString rut = ui->txtRut->text().trimmed(); // trimmed quita espacios de los lados
        QString clave = ui->txtClave->text().trimmed();

        // 1. VALIDACIÓN RUT (EXCEPCIÓN DE FORMATO)
        // La regla dice: "Varios números" + "-" + "Un número o la letra k/K"
        QRegularExpression regexRut("^[0-9]+-[0-9kK]$");
        QRegularExpressionMatch match = regexRut.match(rut);

        if (!match.hasMatch()) {
            // Si no tiene el formato 12345678-9, lanzamos error
            throw std::invalid_argument("El RUT debe tener formato: 12345678-9 (con guion).");
        }

        // 2. Validación de Credenciales (Simulada)
        // Fíjate que ahora comparamos strings limpios
        if (rut == "22036610-3" && clave == "123") {
            QMessageBox::information(this, "Éxito", "¡Bienvenido!", QMessageBox::Ok);

            // Abrir menú y cerrar login
            VentanaMenu *menu = new VentanaMenu();
            menu->show();
            this->close();
        }
        else {
            // Si el formato está bien pero los datos mal
            throw std::runtime_error("RUT o Clave incorrectos.");
        }

    }
    catch (const std::exception &e) {
        QMessageBox::warning(this, "Error de Ingreso", e.what());
    }
}








