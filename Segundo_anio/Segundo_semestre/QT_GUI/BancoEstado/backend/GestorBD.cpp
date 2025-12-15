#include "GestorBD.h"
#include "sqlite3.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

GestorBD::GestorBD(const string& nombreDB) {
    sqlite3* db;
    int resultado = sqlite3_open(nombreDB.c_str(), &db);
    conexion = db;

    if (resultado != SQLITE_OK) {
        throw runtime_error("Error fatal: No se pudo abrir la base de datos.");
    }

    // 1. Tabla Clientes
    const char* sqlClientes =
        "CREATE TABLE IF NOT EXISTS clientes ("
        "rut TEXT PRIMARY KEY, "
        "nombre TEXT NOT NULL, "
        "password TEXT NOT NULL);";

    // 2. Tabla Cuentas
    const char* sqlCuentas =
        "CREATE TABLE IF NOT EXISTS cuentas ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "rut_cliente TEXT NOT NULL, "
        "saldo REAL DEFAULT 0.0, "
        "FOREIGN KEY (rut_cliente) REFERENCES clientes(rut));";

    // 3. Tabla Movimientos
    const char* sqlMovimientos =
        "CREATE TABLE IF NOT EXISTS movimientos ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "tipo TEXT, "       // Transferencia, Deposito
        "rut_origen TEXT, " // Quien envía
        "rut_destino TEXT, "// Quien recibe
        "monto REAL, "
        "fecha TEXT DEFAULT CURRENT_TIMESTAMP);";

    char* errorMsg = nullptr;

    // Ejecutar creaciones
    sqlite3_exec(db, sqlClientes, nullptr, nullptr, &errorMsg);
    if (errorMsg) { cout << "Error tabla Clientes: " << errorMsg << endl; sqlite3_free(errorMsg); }

    sqlite3_exec(db, sqlCuentas, nullptr, nullptr, &errorMsg);
    if (errorMsg) { cout << "Error tabla Cuentas: " << errorMsg << endl; sqlite3_free(errorMsg); }

    sqlite3_exec(db, sqlMovimientos, nullptr, nullptr, &errorMsg);
    if (errorMsg) { cout << "Error tabla Movimientos: " << errorMsg << endl; sqlite3_free(errorMsg); }
}

GestorBD::~GestorBD() {
    if (conexion) {
        sqlite3_close((sqlite3*)conexion);
    }
}

// --- GESTIÓN DE CLIENTES ---

void GestorBD::agregarCliente(string rut, string nombre, string password) {
    sqlite3* db = (sqlite3*)conexion;
    string sql = "INSERT INTO clientes (rut, nombre, password) VALUES (?, ?, ?)";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
        throw runtime_error("Error SQL (Prepare agregarCliente): " + string(sqlite3_errmsg(db)));

    // Usamos el cast -1 (SQLITE_TRANSIENT) para seguridad de memoria
    sqlite3_bind_text(stmt, 1, rut.c_str(), -1, (sqlite3_destructor_type)-1);
    sqlite3_bind_text(stmt, 2, nombre.c_str(), -1, (sqlite3_destructor_type)-1);
    sqlite3_bind_text(stmt, 3, password.c_str(), -1, (sqlite3_destructor_type)-1);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        string error = sqlite3_errmsg(db);
        sqlite3_finalize(stmt);
        throw runtime_error("Error al insertar cliente (posible RUT duplicado): " + error);
    }
    sqlite3_finalize(stmt);
}

vector<ClienteData> GestorBD::obtenerTodosLosClientes() {
    vector<ClienteData> lista;
    sqlite3* db = (sqlite3*)conexion;
    sqlite3_stmt* stmt;
    string sql = "SELECT rut, nombre, password FROM clientes";

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            ClienteData c;
            c.rut = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
            c.nombre = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
            c.password = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
            lista.push_back(c);
        }
    }
    sqlite3_finalize(stmt);
    return lista;
}

void GestorBD::modificarCliente(string rut, string nuevoNombre, string nuevaClave) {
    sqlite3* db = (sqlite3*)conexion;
    string sql = "UPDATE clientes SET nombre = ?, password = ? WHERE rut = ?";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
        throw runtime_error("Error SQL (Prepare modificarCliente): " + string(sqlite3_errmsg(db)));

    sqlite3_bind_text(stmt, 1, nuevoNombre.c_str(), -1, (sqlite3_destructor_type)-1);
    sqlite3_bind_text(stmt, 2, nuevaClave.c_str(), -1, (sqlite3_destructor_type)-1);
    sqlite3_bind_text(stmt, 3, rut.c_str(), -1, (sqlite3_destructor_type)-1);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        sqlite3_finalize(stmt);
        throw runtime_error("Error al modificar cliente: " + string(sqlite3_errmsg(db)));
    }
    sqlite3_finalize(stmt);
}

void GestorBD::eliminarCliente(string rut) {
    sqlite3* db = (sqlite3*)conexion;
    string sql = "DELETE FROM clientes WHERE rut = ?";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
        throw runtime_error("Error SQL (Prepare eliminarCliente)");

    sqlite3_bind_text(stmt, 1, rut.c_str(), -1, (sqlite3_destructor_type)-1);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
}

bool GestorBD::existeCliente(string rut) {
    sqlite3* db = (sqlite3*)conexion;
    sqlite3_stmt* stmt;
    string sql = "SELECT rut FROM clientes WHERE rut = ?";

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) return false;

    sqlite3_bind_text(stmt, 1, rut.c_str(), -1, (sqlite3_destructor_type)-1);
    bool existe = (sqlite3_step(stmt) == SQLITE_ROW);
    sqlite3_finalize(stmt);
    return existe;
}

bool GestorBD::validarCliente(string rut, string password) {
    sqlite3* db = (sqlite3*)conexion;
    string sql = "SELECT count(*) FROM clientes WHERE rut = ? AND password = ?";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) return false;

    sqlite3_bind_text(stmt, 1, rut.c_str(), -1, (sqlite3_destructor_type)-1);
    sqlite3_bind_text(stmt, 2, password.c_str(), -1, (sqlite3_destructor_type)-1);

    bool valido = false;
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        valido = (sqlite3_column_int(stmt, 0) > 0);
    }
    sqlite3_finalize(stmt);
    return valido;
}

// --- GESTIÓN DE CUENTAS ---

int GestorBD::crearCuenta(string rutCliente) {
    sqlite3* db = (sqlite3*)conexion;
    string sql = "INSERT INTO cuentas (rut_cliente, saldo) VALUES (?, 0.0)";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) return -1;

    sqlite3_bind_text(stmt, 1, rutCliente.c_str(), -1, (sqlite3_destructor_type)-1);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        sqlite3_finalize(stmt);
        return -1;
    }

    sqlite3_finalize(stmt);
    return (int)sqlite3_last_insert_rowid(db);
}

int GestorBD::obtenerIdCuentaPorRut(string rut) {
    sqlite3* db = (sqlite3*)conexion;
    string sql = "SELECT id FROM cuentas WHERE rut_cliente = ?";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) return -1;

    sqlite3_bind_text(stmt, 1, rut.c_str(), -1, (sqlite3_destructor_type)-1);

    int id = -1;
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        id = sqlite3_column_int(stmt, 0);
    }
    sqlite3_finalize(stmt);
    return id;
}

double GestorBD::obtenerSaldo(int idCuenta) {
    sqlite3* db = (sqlite3*)conexion;
    string sql = "SELECT saldo FROM cuentas WHERE id = ?";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) return 0.0;

    sqlite3_bind_int(stmt, 1, idCuenta);

    double saldo = 0.0;
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        saldo = sqlite3_column_double(stmt, 0);
    }
    sqlite3_finalize(stmt);
    return saldo;
}

void GestorBD::actualizarSaldo(int idCuenta, double nuevoSaldo) {
    sqlite3* db = (sqlite3*)conexion;
    string sql = "UPDATE cuentas SET saldo = ? WHERE id = ?";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) return;

    sqlite3_bind_double(stmt, 1, nuevoSaldo);
    sqlite3_bind_int(stmt, 2, idCuenta);

    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
}

// --- GESTIÓN DE HISTORIAL (MOVIMIENTOS) ---

void GestorBD::registrarMovimiento(string tipo, string origen, string destino, double monto) {
    sqlite3* db = (sqlite3*)conexion;
    string sql = "INSERT INTO movimientos (tipo, rut_origen, rut_destino, monto) VALUES (?, ?, ?, ?)";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        throw runtime_error("Error SQL (Prepare registrarMovimiento): " + string(sqlite3_errmsg(db)));
    }

    sqlite3_bind_text(stmt, 1, tipo.c_str(), -1, (sqlite3_destructor_type)-1);
    sqlite3_bind_text(stmt, 2, origen.c_str(), -1, (sqlite3_destructor_type)-1);
    sqlite3_bind_text(stmt, 3, destino.c_str(), -1, (sqlite3_destructor_type)-1);
    sqlite3_bind_double(stmt, 4, monto);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        string err = sqlite3_errmsg(db);
        sqlite3_finalize(stmt);
        throw runtime_error("Error al registrar movimiento: " + err);
    }
    sqlite3_finalize(stmt);
}


string GestorBD::obtenerNombreCliente(string rut) {
    sqlite3* db = (sqlite3*)conexion;
    sqlite3_stmt* stmt;
    string sql = "SELECT nombre FROM clientes WHERE rut = ?";
    string nombreEncontrado = "Usuario"; // Valor por defecto si falla

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
        // Usamos el cast -1 para seguridad, igual que en las otras funciones
        sqlite3_bind_text(stmt, 1, rut.c_str(), -1, (sqlite3_destructor_type)-1);

        if (sqlite3_step(stmt) == SQLITE_ROW) {
            // Leemos la columna 0 (nombre)
            const char* val = (const char*)sqlite3_column_text(stmt, 0);
            if (val) {
                nombreEncontrado = string(val);
            }
        }
    }
    sqlite3_finalize(stmt);
    return nombreEncontrado;
}
