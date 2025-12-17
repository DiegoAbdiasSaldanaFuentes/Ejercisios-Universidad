#ifndef GESTORBD_H
#define GESTORBD_H

#include <string>
#include <vector>
#include "sqlite3.h"
#include <QDebug> // Necesario para la sobrecarga del operador

using namespace std;

//  Estructura para datos del cliente
struct ClienteData {
    string rut;
    string nombre;
    string password;
};

struct Movimiento {
    string tipo;        // "Transferencia", Deposito
    string rutOrigen;
    string rutDestino;
    double monto;
    string fecha;
};

// SOBRECARGA DE OPERADOR <<
// Permite usar qdebug() << movimiento;
inline QDebug operator<<(QDebug debug, const Movimiento &m) {
    QDebugStateSaver saver(debug);
    debug.nospace() << "Movimiento(Tipo: " << QString::fromStdString(m.tipo)
                    << ", Monto: $" << m.monto
                    << ", Fecha: " << QString::fromStdString(m.fecha) << ")";
    return debug;
}


class GestorBD {
private:
    sqlite3* conexion;
    void abrirConexion(string nombreDB);
    void cerrarConexion();

public:
    GestorBD(string nombreDB);
    ~GestorBD();

    // CRUD
    void agregarCliente(string rut, string nombre, string password);
    vector<ClienteData> obtenerTodosLosClientes();
    void modificarCliente(string rut, string nombre, string password);
    void eliminarCliente(string rut);
    bool existeCliente(string rut);
    bool validarCliente(string rut, string password);
    string obtenerNombreCliente(string rut); // Bienvenida personalizada

    // Cuentas
    int crearCuenta(string rutCliente);
    int obtenerIdCuentaPorRut(string rut);
    void actualizarSaldo(int idCuenta, double nuevoSaldo);

    // SOBRECARGA DE MÉTODO
    double obtenerSaldo(int idCuenta); // Original por ID)
    double obtenerSaldo(string rut);   // Sobrecarga por RUT)


    void registrarMovimiento(string tipo, string origen, string destino, double monto);
    vector<Movimiento> obtenerHistorial(string rut);
};

#endif // AAAAAAAA
