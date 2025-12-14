#ifndef GESTORBD_H
#define GESTORBD_H

#include <string>
#include <vector>
#include "sqlite3.h"

using namespace std;

// Estructura para datos del cliente
struct ClienteData {
    string rut;
    string nombre;
    string password;
};

// --- NUEVA ESTRUCTURA: EL RECIBO ---
struct Movimiento {
    string tipo;        // "Transferencia" o "Deposito"
    string rutOrigen;   // Quién envió (o "Banco" si es depósito)
    string rutDestino;  // Quién recibió
    double monto;
    string fecha;       // Opcional (por ahora guardaremos texto simple)
};

class GestorBD {
private:
    void* conexion;

public:
    GestorBD(const string& nombreDB);
    ~GestorBD();

    // Clientes
    void agregarCliente(string rut, string nombre, string password);
    vector<ClienteData> obtenerTodosLosClientes();
    void modificarCliente(string rut, string nuevoNombre, string nuevaClave);
    void eliminarCliente(string rut);
    bool existeCliente(string rut);
    bool validarCliente(string rut, string password);

    // Cuentas
    int crearCuenta(string rutCliente);
    int obtenerIdCuentaPorRut(string rut);
    double obtenerSaldo(int idCuenta);
    void actualizarSaldo(int idCuenta, double nuevoSaldo);

    // --- NUEVAS FUNCIONES PARA EL HISTORIAL ---
    // 1. Guardar un movimiento
    void registrarMovimiento(string tipo, string origen, string destino, double monto);

    // 2. Leer los movimientos de UNA persona
    vector<Movimiento> obtenerHistorial(string rutUsuario);
};

#endif // GESTORBD_H
