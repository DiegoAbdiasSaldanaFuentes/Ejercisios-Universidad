#ifndef CLIENTE_H
#define CLIENTE_H

#include <QString>
#include <QList>
#include "persona.h" // NUEVO: Importamos al padre

struct Movimiento {
    QString rut;
    QString banco;
    int monto;
};

// NUEVO: Heredamos de Persona
class Cliente : public Persona
{
private:
    static int saldoCuenta;
    static QString nombreUsuario;
    static QList<Movimiento> listaMovimientos;

public:
    Cliente();

    // NUEVO: Debemos implementar la función del padre
    // Al ser static el resto, esta debe ser normal para cumplir con la herencia
    QString getIdentificacion() override;

    // ... (Tus otros métodos estáticos siguen igual abajo) ...
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

#endif // CLIENTE_H
