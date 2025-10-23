#include <iostream>
#include <vector>
#include <string>
using namespace std;



// Empresa 1:n
// Vehiculos n:m
// Autos etc 1:n

class Empresa{
public:

    string nombre_empresa;
    Empresa(){
        nombre_empresa = "Sin nombre";
    }

    Empresa(string nom) : nombre_empresa(nom){}
};

class Vehiculos{
public:
    int numero_identificacion;
    string marca;
    string modelo;
    int anio_fabricacion;

    Vehiculos(){
        numero_identificacion = 0;
        marca = "Sin marca";
        modelo = "Sin modelo";
        anio_fabricacion = 0;

    }

    Vehiculos( int num_id,string ma, string mod, int ani) : numero_identificacion(num_id),marca(ma), modelo(mod), anio_fabricacion(ani) {}


};

class Auto{
public:

vector<Vehiculos*> automoviles;
};
