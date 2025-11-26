#include "loginwindow.h"
#include "./ui_loginwindow.h"
#include <QMessageBox>
#include "ventanamenu.h"

LoginWindow::LoginWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::LoginWindow){
    ui->setupUi(this);
}

LoginWindow::~LoginWindow(){
    delete ui;
}

void LoginWindow::on_btnIngresar_clicked()
{
    // trimmed() borra los espacios invisibles al inicio y final
    QString rut = ui->txtRut->text().trimmed();
    QString clave = ui->txtClave->text().trimmed();


    /* Esto me dice que estoy insertando para depuracion
    QMessageBox::information(this, "Ojo de Halcón","Rut recibido: [" + rut + "]\nClave recibida: [" + clave + "]",QMessageBox::Ok);
    */

    // Validacion
    if (rut == "123" && clave == "admin") {
        QMessageBox::information(this, "Éxito", "¡Bienvenido!", QMessageBox::Ok);

        // Se crea el objeto de la nueva ventana y reservamos memoria
        VentanaMenu *menu = new VentanaMenu();

        // Mostrar
        menu->show();

        // Cerrar
        this->close();

    }
    else {
        QMessageBox::warning(this, "Error", "Clave o Rut incorrectos", QMessageBox::Ok);
    }
}








