#include "ventanahistorial.h"
#include "ui_ventanahistorial.h"
#include <QMessageBox>

VentanaHistorial::VentanaHistorial(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VentanaHistorial)
{
    ui->setupUi(this);
    // NO TOCAMOS LA TABLA VISUAL PARA NADA.
    // ASÍ EVITAMOS EL CRASH AL 100%.
}

VentanaHistorial::~VentanaHistorial()
{
    delete ui;
}

void VentanaHistorial::setRutUsuario(std::string rut) {
    this->rutUsuario = rut;

    // Ejecutamos la carga apenas se abre la ventana
    cargarDatos();
}

void VentanaHistorial::cargarDatos() {
    try {
        // 1. Conectar BD
        GestorBD gestor("banco.db");

        // 2. Obtener datos
        vector<Movimiento> historial = gestor.obtenerHistorial(rutUsuario);

        // 3. CONSTRUIR EL TEXTO DEL REPORTE
        QString reporte = "=== HISTORIAL DE MOVIMIENTOS ===\n\n";

        if (historial.empty()) {
            reporte += "No hay movimientos registrados para este usuario.";
        } else {
            for (const Movimiento &m : historial) {
                reporte += "Tipo: " + QString::fromStdString(m.tipo) + "\n";
                reporte += "Origen: " + QString::fromStdString(m.rutOrigen) + "\n";
                reporte += "Destino: " + QString::fromStdString(m.rutDestino) + "\n";
                reporte += "Monto: $" + QString::number(m.monto) + "\n";
                reporte += "Fecha: " + QString::fromStdString(m.fecha) + "\n";
                reporte += "-----------------------------------\n";
            }
        }

        // 4. MOSTRARLO EN PANTALLA (Pop-up)
        // Esto detiene la ventana vacía y muestra el texto encima.
        QMessageBox::information(this, "Historial Seguro", reporte);

    } catch (const std::exception &e) {
        QMessageBox::critical(this, "Error", e.what());
    }
}
