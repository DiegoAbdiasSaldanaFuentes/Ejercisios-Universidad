#ifndef CLIENTE_H
#define CLIENTE_H

#include <QString>
#include <QList>

// DEFINICIÓN DE LA ESTRUCTURA
struct Movimiento {
    QString rut;
    QString banco;
    int monto;
};

class Cliente
{
private:
    static int saldoCuenta;
    static QString nombreUsuario;

    // 2. DECLARACIÓN DE LA LISTA (Exactamente este nombre)
    static QList<Movimiento> listaMovimientos;

public:
    Cliente();

    static int getSaldo();
    static QString getNombre();
    static void disminuirSaldo(int monto);
    static void aumentarSaldo(int monto);
    static void setNombre(QString nombre);

    // Métodos nuevos para el historial
    static void agregarMovimiento(QString rut, QString banco, int monto);
    static QList<Movimiento>& getMovimientos();
    static void eliminarMovimiento(int indice);
};

#endif // CLIENTE_H
