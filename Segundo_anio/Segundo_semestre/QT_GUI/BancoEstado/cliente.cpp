#include "cliente.h"

// 1. INICIALIZACIÓN DE VARIABLES ESTÁTICAS (¡Esto es lo que te falta!)
QList<Movimiento> Cliente::listaMovimientos;
int Cliente::saldoCuenta = 500000;
QString Cliente::nombreUsuario = "Usuario Prueba";

// 2. CONSTRUCTOR
Cliente::Cliente() {
}

// 3. IMPLEMENTACIÓN DE MÉTODOS

int Cliente::getSaldo() {
    return saldoCuenta;
}

QString Cliente::getNombre() {
    return nombreUsuario;
}

void Cliente::disminuirSaldo(int monto) {
    saldoCuenta = saldoCuenta - monto;
}

void Cliente::aumentarSaldo(int monto) {
    saldoCuenta = saldoCuenta + monto;
}

void Cliente::setNombre(QString nombre) {
    nombreUsuario = nombre;
}

// 4. MÉTODOS DE HISTORIAL

void Cliente::agregarMovimiento(QString rut, QString banco, int monto) {
    Movimiento nuevo;
    nuevo.rut = rut;
    nuevo.banco = banco;
    nuevo.monto = monto;

    listaMovimientos.append(nuevo);
}

QList<Movimiento>& Cliente::getMovimientos() {
    return listaMovimientos;
}

void Cliente::eliminarMovimiento(int indice) {
    if (indice >= 0 && indice < listaMovimientos.size()) {
        listaMovimientos.removeAt(indice);
    }
}

// Implementación de la sobrecarga
void Cliente::operator+=(int monto) {
    // Reutilizamos nuestro método estático
    Cliente::aumentarSaldo(monto);
}

// Implementación del método obligatorio de Persona
QString Cliente::getIdentificacion() {
    return "Cliente: " + nombreUsuario;
}
