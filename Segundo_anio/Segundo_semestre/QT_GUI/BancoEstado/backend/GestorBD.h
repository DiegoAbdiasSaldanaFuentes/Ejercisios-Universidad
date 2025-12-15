#ifndef GESTORBD_H
#define GESTORBD_H

#include <string>
#include <vector>
#include "sqlite3.h"
#include <QDebug> // Necesario para la sobrecarga del operador

using namespace std;

// 1. Estructura para datos del cliente
struct ClienteData {
    string rut;
    string nombre;
    string password;
};

// 2. Estructura para el Historial
struct Movimiento {
    string tipo;        // "Transferencia", "Deposito", etc.
    string rutOrigen;
    string rutDestino;
    double monto;
    string fecha;
};

// 3. [REQUISITO] SOBRECARGA DE OPERADOR <<
// Permite usar qDebug() << movimiento;
inline QDebug operator<<(QDebug debug, const Movimiento &m) {
    QDebugStateSaver saver(debug);
    debug.nospace() << "Movimiento(Tipo: " << QString::fromStdString(m.tipo)
                    << ", Monto: $" << m.monto
                    << ", Fecha: " << QString::fromStdString(m.fecha) << ")";
    return debug;
}

// 4. CLASE PRINCIPAL (¡Solo una definición!)
class GestorBD {
private:
    sqlite3* conexion; // Usamos el tipo real porque incluimos sqlite3.h
    void abrirConexion(string nombreDB);
    void cerrarConexion();

public:
    GestorBD(string nombreDB);
    ~GestorBD();

    // --- Clientes (CRUD y Auth) ---
    void agregarCliente(string rut, string nombre, string password);
    vector<ClienteData> obtenerTodosLosClientes();
    void modificarCliente(string rut, string nombre, string password); // Ajusté nombres para coincidir con .cpp
    void eliminarCliente(string rut);
    bool existeCliente(string rut);
    bool validarCliente(string rut, string password);
    string obtenerNombreCliente(string rut); // Bienvenida personalizada

    // --- Cuentas ---
    int crearCuenta(string rutCliente);
    int obtenerIdCuentaPorRut(string rut);
    void actualizarSaldo(int idCuenta, double nuevoSaldo);

    // --- [REQUISITO] SOBRECARGA DE MÉTODO ---
    double obtenerSaldo(int idCuenta); // Original (por ID)
    double obtenerSaldo(string rut);   // Sobrecarga (por RUT)

    // --- Historial ---
    void registrarMovimiento(string tipo, string origen, string destino, double monto);
    vector<Movimiento> obtenerHistorial(string rut); // ¡Te faltaba declarar esta!
};

#endif // GESTORBD_H
