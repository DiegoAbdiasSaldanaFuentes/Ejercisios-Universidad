#include <iostream>
#include <string>
using namespace std;

class Tarea{
public:
    string titulo;
    int codigo;
    Tarea(){ //costructor base
        titulo = "Sin nombre";
        codigo = 0;
    }
    Tarea(string tit, int cod){//constructor
        titulo = tit;
        codigo = cod;
    }
    virtual void mostrarInfo() const = 0; //metodos abstractos
    virtual void mostrarInfo() const = 0;
    virtual ~Tarea(){}//destructor
};

Tarea::~Tarea(){};

class Evaluable{
public:
    int porcentajeAvance;

    Evaluable(){
        porcentajeAvance = 50;
    }

    Evaluable(int porcentaje){
        porcentajeAvance = porcentaje;
    }

    double  calcularProgresoBase(double completado) const{
        return (completado * porcentajeAvance) / 100.0;
    }
};

class NoEvaluable{
public:
    void mostrasInfoBasica(string titulo, int codigo) const {
        cout <<"Titulo: "<< titulo<<" Codigo: "<< codigo <<endl;
    }
};

class TareaPractica: public Tarea, public Evaluable{
public:

};

class Lectura : public Tarea, public NoEvaluable{
public:

};