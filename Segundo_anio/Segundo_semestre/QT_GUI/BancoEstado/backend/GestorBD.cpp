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
        throw runtime_error("Error al abrir la base de datos");
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

    // 3. --- NUEVA TABLA: MOVIMIENTOS ---
    const char* sqlMovimientos =
        "CREATE TABLE IF NOT EXISTS movimientos ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "tipo TEXT, "       // Transferencia, Deposito
        "rut_origen TEXT, " // Quien envía
        "rut_destino TEXT, "// Quien recibe
        "monto REAL, "
        "fecha TEXT DEFAULT CURRENT_TIMESTAMP);"; // Fecha automática

    char* errorMsg = nullptr;
    sqlite3_exec(db, sqlClientes, nullptr, nullptr, &errorMsg);
    sqlite3_exec(db, sqlCuentas, nullptr, nullptr, &errorMsg);

    // Ejecutamos la creación de la tabla movimientos
    sqlite3_exec(db, sqlMovimientos, nullptr, nullptr, &errorMsg);

    if (errorMsg) {
        string err = errorMsg;
        sqlite3_free(errorMsg);
        // No lanzamos error fatal, pero imprimimos por si acaso
        cout << "SQL Error: " << err << endl;
    }
}

GestorBD::~GestorBD() {
    if (conexion) {
        sqlite3_close((sqlite3*)conexion);
    }
}

// ... (Tus funciones de Clientes y Cuentas siguen igual, las omito para no hacer spam,
//      PERO ASEGÚRATE DE NO BORRARLAS. Si copias todo, mantén las de antes o pide el código completo).
// ... [MANTÉN AQUÍ TUS FUNCIONES DE AGREGAR, OBTENER, ELIMINAR CLIENTES Y CUENTAS] ...
// ... Si quieres te paso el archivo ENTERO de nuevo para evitar errores de copy-paste.

// --- AQUÍ PEGARÉ LAS FUNCIONES DE ARRIBA RESUMIDAS PARA QUE EL CÓDIGO SEA COMPLETO ---
// (Te doy el bloque completo abajo para reemplazar todo el archivo sin miedo)

// =========================================================
// PEGA ESTO EN TU ARCHIVO GestorBD.cpp COMPLETO
// =========================================================

void GestorBD::agregarCliente(string rut, string nombre, string password) {
    sqlite3* db = (sqlite3*)conexion;
    string sql = "INSERT INTO clientes (rut, nombre, password) VALUES (?, ?, ?)";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) throw runtime_error("Error SQL agregarCliente");
    sqlite3_bind_text(stmt, 1, rut.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, nombre.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, password.c_str(), -1, SQLITE_STATIC);
    sqlite3_step(stmt);
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
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) throw runtime_error("Error SQL modificar");
    sqlite3_bind_text(stmt, 1, nuevoNombre.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, nuevaClave.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, rut.c_str(), -1, SQLITE_STATIC);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
}

void GestorBD::eliminarCliente(string rut) {
    sqlite3* db = (sqlite3*)conexion;
    string sql = "DELETE FROM clientes WHERE rut = ?";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) throw runtime_error("Error SQL eliminar");
    sqlite3_bind_text(stmt, 1, rut.c_str(), -1, SQLITE_STATIC);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
}

bool GestorBD::existeCliente(string rut) {
    sqlite3* db = (sqlite3*)conexion;
    sqlite3_stmt* stmt;
    string sql = "SELECT rut FROM clientes WHERE rut = ?";
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) return false;
    sqlite3_bind_text(stmt, 1, rut.c_str(), -1, SQLITE_STATIC);
    bool existe = (sqlite3_step(stmt) == SQLITE_ROW);
    sqlite3_finalize(stmt);
    return existe;
}

bool GestorBD::validarCliente(string rut, string password) {
    sqlite3* db = (sqlite3*)conexion;
    string sql = "SELECT count(*) FROM clientes WHERE rut = ? AND password = ?";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) return false;
    sqlite3_bind_text(stmt, 1, rut.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, password.c_str(), -1, SQLITE_STATIC);
    bool valido = false;
    if (sqlite3_step(stmt) == SQLITE_ROW) valido = (sqlite3_column_int(stmt, 0) > 0);
    sqlite3_finalize(stmt);
    return valido;
}

int GestorBD::crearCuenta(string rutCliente) {
    sqlite3* db = (sqlite3*)conexion;
    string sql = "INSERT INTO cuentas (rut_cliente, saldo) VALUES (?, 0.0)";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) return -1;
    sqlite3_bind_text(stmt, 1, rutCliente.c_str(), -1, SQLITE_STATIC);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    return (int)sqlite3_last_insert_rowid(db);
}

int GestorBD::obtenerIdCuentaPorRut(string rut) {
    sqlite3* db = (sqlite3*)conexion;
    string sql = "SELECT id FROM cuentas WHERE rut_cliente = ?";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) return -1;
    sqlite3_bind_text(stmt, 1, rut.c_str(), -1, SQLITE_STATIC);
    int id = -1;
    if (sqlite3_step(stmt) == SQLITE_ROW) id = sqlite3_column_int(stmt, 0);
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
    if (sqlite3_step(stmt) == SQLITE_ROW) saldo = sqlite3_column_double(stmt, 0);
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

// --- NUEVAS FUNCIONES DE HISTORIAL ---

void GestorBD::registrarMovimiento(string tipo, string origen, string destino, double monto) {
    sqlite3* db = (sqlite3*)conexion;
    // Insertamos los datos. La fecha la pone SQLite sola (CURRENT_TIMESTAMP)
    string sql = "INSERT INTO movimientos (tipo, rut_origen, rut_destino, monto) VALUES (?, ?, ?, ?)";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        throw runtime_error("Error SQL al registrar movimiento");
    }

    sqlite3_bind_text(stmt, 1, tipo.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, origen.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, destino.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_double(stmt, 4, monto);

    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
}
vector<Movimiento> GestorBD::obtenerHistorial(string rutUsuario) {
    vector<Movimiento> lista;
    sqlite3* db = (sqlite3*)conexion;
    sqlite3_stmt* stmt;

    string sql = "SELECT tipo, rut_origen, rut_destino, monto, fecha FROM movimientos "
                 "WHERE rut_origen = ? OR rut_destino = ? ORDER BY id DESC";

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        return lista; // Si falla la consulta, devolvemos lista vacía y NO cerramos el programa
    }

    sqlite3_bind_text(stmt, 1, rutUsuario.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, rutUsuario.c_str(), -1, SQLITE_STATIC);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        Movimiento m;

        // --- BLINDAJE ANTI-CRASH ---
        // Verificamos si la columna tiene texto o es NULL
        const char* txtTipo = (const char*)sqlite3_column_text(stmt, 0);
        const char* txtOrigen = (const char*)sqlite3_column_text(stmt, 1);
        const char* txtDestino = (const char*)sqlite3_column_text(stmt, 2);
        const char* txtFecha = (const char*)sqlite3_column_text(stmt, 4);

        // Usamos operador ternario: Si existe ? úsalo : si no, pon texto genérico
        m.tipo = txtTipo ? string(txtTipo) : "Transferencia";
        m.rutOrigen = txtOrigen ? string(txtOrigen) : "Desconocido";
        m.rutDestino = txtDestino ? string(txtDestino) : "Desconocido";
        m.monto = sqlite3_column_double(stmt, 3);
        m.fecha = txtFecha ? string(txtFecha) : "--";

        lista.push_back(m);
    }

    sqlite3_finalize(stmt);
    return lista;
}
