#include <iostream>
#include <string>
#include "GestorBD.h"
using namespace std;

class Persona {
    private:
        string rut, nombre;
    
    public:
        Persona(string r, string n): rut(r), nombre(n){}

        virtual void mostrarInfo() = 0;

        string getRut(){ 
            return rut;
        }

        string getNombre(){
            return nombre;
        }
};

class Cliente : public Persona {
    private:
        string password;

    public:
        Cliente(string r, string n, string p, GestorBD* bd) : Persona(r, n), password(p) {
        bd->agregarCliente(r, n, p);
        }

        void mostrarInfo() override {
        cout << "Cliente: " << getNombre() << " (RUT: " << getRut() << ")" << endl;
        }

        bool validarPass(string p){ 
            return p == password; 
        }
};

class CuentaBancaria {
    private:
        int numeroCuenta;
        int idCuenta;
        Cliente* titular;
        double saldo;
        GestorBD* gestor;

    public:
        CuentaBancaria(Cliente* c, GestorBD* g) {
            titular = c;
            gestor = g;
        
            int idExistente = gestor->obtenerIdCuentaPorRut(c->getRut());
        
            if (idExistente != -1) {
                this->idCuenta = idExistente;
                this->saldo = gestor->obtenerSaldo(idCuenta);
            } else {
                this->idCuenta = gestor->crearCuenta(c->getRut());
                this->saldo = 0.0;
            }
        }
        
        void depositar(double monto) {
            if (monto <= 0) throw string("Monto inválido");
            saldo += monto;
            gestor->actualizarSaldo(idCuenta, saldo); // Actualiza por ID
        }
    
        void retirar(double monto) {
            if (monto > saldo) throw string("Fondos insuficientes");
            saldo -= monto;
            gestor->actualizarSaldo(idCuenta, saldo);
        }
    
        void transferir(string rutDestino, double monto) {
            if (monto > saldo) throw string("Sin fondos");
            
            // 1. Buscamos la cuenta destino
            int idDestino = gestor->obtenerIdCuentaPorRut(rutDestino);
            if (idDestino == -1) throw string("El destinatario no existe");
    
            // 2. Quitamos de MI cuenta
            this->retirar(monto); 
    
            // 3. Sumamos a la OTRA cuenta (Directo a la BD para no cargar otro objeto)
            double saldoDestino = gestor->obtenerSaldo(idDestino);
            gestor->actualizarSaldo(idDestino, saldoDestino + monto);
        }
    
        double getSaldo(){ 
            return saldo; 
        }

        int getId(){ 
            return idCuenta; 
        } 
};



