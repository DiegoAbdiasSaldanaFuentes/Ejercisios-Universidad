#include "loginwindow.h"
#include "./ui_loginwindow.h"
#include <QMessageBox>

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
    // 1. .trimmed() borra los espacios invisibles al inicio y final
    QString rut = ui->txtRut->text().trimmed();
    QString clave = ui->txtClave->text().trimmed();


    /* Esto me dice que estoy insertando para depuracion
    QMessageBox::information(this, "Ojo de Halcón",
                             "Rut recibido: [" + rut + "]\nClave recibida: [" + clave + "]",
                             QMessageBox::Ok);
    */
    // 3. Validación (Aquí puse que la clave sea "123" para que te funcione)
    if (rut == "123" && clave == "admin") {
        QMessageBox::information(this, "Éxito", "¡Bienvenido!", QMessageBox::Ok);
    }
    else {
        QMessageBox::warning(this, "Error", "Clave o Rut incorrectos", QMessageBox::Ok);
    }
}








