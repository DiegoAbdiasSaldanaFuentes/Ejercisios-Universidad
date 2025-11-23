#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnIngresar_clicked()
{
    QString claveIngresada = ui ->txtClave->text();

    if(claveIngresada == "1234"){
        this ->setWindowTitle("Acceso Concedido");
    }else{
        this->setWindowTitle("Error: Clave incorrecta");
    }
}

