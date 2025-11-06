#include <iostream>
#include <string>
using namespace std;

class Actividad{
public:
    string nombre;
    int codigo;
    int duracion_horas;

    Actividad(){
        nombre= "Sin nombre";
        codigo = 0;
        duracion_horas = 0;
    }

    Actividad(string nom, int cod, int dur){
        nombre = nom;
        codigo = cod;
        duracion_horas = dur;
    }

    virtual void mostrarInfo() const = 0;
    virtual void calcularNota() const = 0;
    virtual ~Actividad(){} // Buena practica
};

class Evaluable{
public:
    float peso;

    Evaluable(){
        peso = 10.0;
    }

    Evaluable(int pes){
        peso = pes;
    }


    double calcularNotaBase(double notaObtenida){

    }
};

class NoEvaluable : public Evaluable{
public:
    int mostrar_actividad(){

    }
    
};

class ClaseTeorica : public Actividad, public Evaluable{
public:


};

class Laboratorio :  public Actividad, public Evaluable{
public:


};

class ProyectoInvestigacion : public Actividad, public Evaluable{
public:


};

class Taller : public Actividad,  public NoEvaluable{
public:


};


int main(){


    return 0;
}