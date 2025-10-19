#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Cliente{
public:
    string nombre;
    string direccion;
    int numero_cliente;

    Cliente(){
        nombre = "Sin nombre";
        direccion = "Sin direccion";
        numero_cliente = 0;
    }

    Cliente(string nom, string dir, int num_c): nombre(nom), direccion(dir), numero_cliente(num_c) {}
};

class Producto{
    string nombre;
    int precio;
    int cantidad;

    Producto(){
        nombre = "Sin nombre";
        precio = 0;
        cantidad = 0;
    }

    Producto(string nom, int pr, int can): nombre(nom), precio(pr), cantidad(can) {}
};


class Factura{ //agregacion
private:
    Cliente* cliente;
    vector<Cliente*> boleta;

public:
    void agregar(Cliente* e){
        boleta.push_back(e);
    }

    void mostrarBoleta(){
        cout << "Los productos comprados son: \n";
        for(auto e : boleta){
            cout << "-" << e -> nombre<< endl;
        }
    }
};