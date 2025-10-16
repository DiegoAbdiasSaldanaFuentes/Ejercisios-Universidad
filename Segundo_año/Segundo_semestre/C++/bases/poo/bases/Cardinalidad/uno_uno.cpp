#include <iostream>
#include <string>
using namespace std;

class Profesor{
public:
    string nombre;
    Profesor(string n) : nombre(n){}
    void  mostrar() { cout << "Profesor: " << nombre <<endl;}
};

class Curso{
public:
    string nombre;
    Curso(string n) : nombre(n){}
    void asignarProfesor(Profesor& p){
        cout << "Curso: "<< nombre << " tiene  como profesor a ";
        p.mostrar();
    }
};

int main(){
    Profesor profe("Philip Vásquez");
    Curso poo("Programación Orientada a objetos");
    
    poo.asignarProfesor(profe); // Asociación Temporal
}



