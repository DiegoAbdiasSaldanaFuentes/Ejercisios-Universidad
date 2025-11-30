#ifndef CLIENTE_H
#define CLIENTE_H

#include <QString>
#include <QList>
#include "persona.h"

struct Movimiento {
    QString rut;
    QString banco;
    int monto;
};


class Cliente : public Persona
{
private:
    static int saldoCuenta;
    static QString nombreUsuario;
    static QList<Movimiento> listaMovimientos;

public:
    Cliente();



    QString getIdentificacion() override;


    static int getSaldo();
    static QString getNombre();
    static void disminuirSaldo(int monto);
    static void aumentarSaldo(int monto);
    static void setNombre(QString nombre);
    static void agregarMovimiento(QString rut, QString banco, int monto);
    static QList<Movimiento>& getMovimientos();
    static void eliminarMovimiento(int indice);
    void operator+=(int monto);
};

#endif
