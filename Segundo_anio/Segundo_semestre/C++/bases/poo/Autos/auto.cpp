#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Vehiculo{
private:
    string marca;
    string modelo;
    int anio;
public:
    Vehiculo(): marca("sin marca"), modelo("sin modelo"), anio(0){}
    Vehiculo(string ma, string mo, int i): marca(ma), modelo(mo), anio(i){}

    string getMarca() const {return marca;}
    string getModelo()const {return modelo;}
    int getAnio() const {return anio;}

    virtual void mostrar() const = 0;
    virtual ~Vehiculo(){}
};

class Auto : Vehiculo{
private:
    int puertas;
public:
    Auto(): Vehiculo(){}
    Auto(string ma, string mo, int i, int p):Vehiculo(ma,mo,i), puertas(p){} 
    int getPuertas() const {return puertas;}

    void mostrar() const override{
        cout<<"Vehiculo: "<< getMarca() << endl;
        cout<<"Modelo: "<<getModelo()<<endl;
        cout<<"Anio: "<<getAnio()<<endl;
        cout<<"Puertas: "<<getPuertas()<<endl;
    }

};

class Moto : Vehiculo{
private:
    string cilindrada;
public:
    Moto(): Vehiculo(){}
    Moto(string ma, string mo, int i, string ci):Vehiculo(ma,mo,i), cilindrada(ci){} 
    string getCilindro() const {return cilindrada;}

    void mostrar() const override{
        cout<<"Vehiculo: "<<getMarca()<<endl;
        cout<<"Modelo: "<<getModelo()<<endl;
        cout<<"Anio: "<<getAnio()<<endl;
        cout<<"cilindrada: "<<getCilindro()<<endl;
    }
};

int main(){
    Auto a("TOYOTA", "Corolla", 2024, 4);
    a.mostrar();


}