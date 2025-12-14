
#include <iostream>
#include <string>
#include "GestorBD.h"
#include "BANCO_CMM.cpp"

using namespace std;

int main() {
    cout << "==========================================" << endl;
    cout << "   BANCO NO ESTADO" << endl;
    cout << "==========================================" << endl;
    
    try {
        // ===== 1. INICIALIZAR BASE DE DATOS =====
        cout << "\n[1] INICIALIZANDO BASE DE DATOS " << endl;
        GestorBD gestor("banco.db");
        cout << "     Base de datos creada/abierta" << endl;
        
        // ===== 2. CREAR PRIMER CLIENTE =====
        cout << "\n[2] CREANDO PRIMER CLIENTE..." << endl;
        Cliente* cliente1 = new Cliente("11111111-1", "Juan Perez", "clave123", &gestor);
        cliente1->mostrarInfo();
        
        // ===== 3. CREAR CUENTA BANCARIA =====
        cout << "\n[3] CREANDO CUENTA BANCARIA..." << endl;
        CuentaBancaria cuenta1(cliente1, &gestor);
        cout << "     Cuenta ID: " << cuenta1.getId() << endl;
        cout << "    Saldo inicial: $" << cuenta1.getSaldo() << endl;
        
        // ===== 4. OPERACIONES BANCARIAS =====
        cout << "\n[4] OPERACIONES BANCARIAS:" << endl;
        
        cout << "\n    a) DEPOSITO: $10,000" << endl;
        cuenta1.depositar(10000);
        cout << "       Nuevo saldo: $" << cuenta1.getSaldo() << endl;
        
        cout << "\n    b) RETIRO: $2,500" << endl;
        cuenta1.retirar(2500);
        cout << "       Nuevo saldo: $" << cuenta1.getSaldo() << endl;
        
        // ===== 5. SEGUNDO CLIENTE =====
        cout << "\n[5] CREANDO SEGUNDO CLIENTE..." << endl;
        Cliente* cliente2 = new Cliente("22222222-2", "Maria Gonzalez", "clave456", &gestor);
        cliente2->mostrarInfo();
        CuentaBancaria cuenta2(cliente2, &gestor);
        
        // ===== 6. TRANSFERENCIA =====
        cout << "\n[6] TRANSFERENCIA ENTRE CUENTAS:" << endl;
        cout << "    Transferir $3,000 de Juan a Maria" << endl;
        cuenta1.transferir("22222222-2", 3000);
        
        cout << "\n    RESULTADOS:" << endl;
        cout << "    - Saldo Juan: $" << cuenta1.getSaldo() << endl;
        cout << "    - Saldo Maria: $" << cuenta2.getSaldo() << endl;
        
        // ===== 7. DEMOSTRACION DE EXCEPCIONES =====
        cout << "\n[7] DEMOSTRACION DE MANEJO DE ERRORES:" << endl;
        try {
            cout << "    Intentando retirar $10,000 (debe fallar)..." << endl;
            cuenta1.retirar(10000);
        } catch (const string& error) {
            cout << "     Excepcion capturada: " << error << endl;
        }
        
        // ===== 8. VERIFICAR PERSISTENCIA =====
        cout << "\n[8] VERIFICANDO PERSISTENCIA EN BD:" << endl;
        cout << "    Consultando datos directamente desde SQLite..." << endl;
        
        cout << "\n    Datos en base de datos 'banco.db':" << endl;
        cout << "    - ID cuenta de Juan: " << gestor.obtenerIdCuentaPorRut("11111111-1") << endl;
        cout << "    - ID cuenta de Maria: " << gestor.obtenerIdCuentaPorRut("22222222-2") << endl;
        cout << "    - Saldo de Juan desde BD: $" << gestor.obtenerSaldo(cuenta1.getId()) << endl;
        
        // ===== 9. RESUMEN =====
        cout << "\n[9] RESUMEN DE CONCEPTOS IMPLEMENTADOS:" << endl;
        cout << "     Herencia (Persona → Cliente)" << endl;
        cout << "     Clase abstracta (Persona)" << endl;
        cout << "     Polimorfismo (mostrarInfo())" << endl;
        cout << "     Encapsulamiento (datos privados)" << endl;
        cout << "     Excepciones (3 tipos diferentes)" << endl;
        cout << "     Agregación (Cuenta tiene Cliente)" << endl;
        cout << "     Conexión a BD real (SQLite)" << endl;
        cout << "     Operaciones CRUD completas" << endl;
        
        // ===== 10. INSTRUCCIONES FINALES =====
        cout << "\n[10] BASE DE DATOS CREADA:" << endl;
        cout << "    Archivo: banco.db" << endl;
        cout << "    Para ver los datos, abre CMD y ejecuta:" << endl;
        cout << "      sqlite3 banco.db" << endl;
        cout << "      .tables" << endl;
        cout << "      SELECT * FROM Clientes;" << endl;
        cout << "      SELECT * FROM Cuentas;" << endl;
        
        // Limpiar memoria
        delete cliente1;
        delete cliente2;
        
    } catch (const exception& e) {
        cerr << "\n[ERROR DE SISTEMA] " << e.what() << endl;
        return 1;
    } catch (const string& e) {
        cerr << "\n[ERROR DE NEGOCIO] " << e << endl;
        return 1;
    }
    
    cout << "\n==========================================" << endl;
    cout << "   PROGRAMA EJECUTADO EXITOSAMENTE" << endl;
    cout << "==========================================" << endl;
    
    cout << "\nPresiona Enter para salir...";
    cin.get();
    
    return 0;
}