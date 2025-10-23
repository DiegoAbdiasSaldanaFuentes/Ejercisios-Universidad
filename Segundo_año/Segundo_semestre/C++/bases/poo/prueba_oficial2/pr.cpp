// Sistema academico
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;


class Persona{ // Persona es 1:m

public:
    string nombre;
    string rut;
    string correo;

    Persona(){
        nombre = "Sin nombre";
        rut = "Sin rut";
        correo = "Sin correo";

    }
    Persona(string n, string r, string c) : nombre(n), rut(r), correo(c){
        cout<<"persona creada\n"<<endl;
    }
    virtual void mostrar() const = 0;

};


class Asignatura{ // estudiantes y asignatura es n:m
public:
    int codigo;
    string asignaturas;
    int cupos;

    Asignatura(){
        asignaturas = "Sin asignatura";
        codigo = 0;
        cupos = 0;
    }

    Asignatura(int c, string asig, int cup) : codigo(c), asignaturas(asig), cupos(cup){}
    // profesor a cargo mediante asociacion
    // buscar codigo de asignacion y agregacion
    Profesores* profesor;// asosiacion
    vector<Carrera*> carreras; //agregacion
    vector<Estudiantes*> inscribire;

    void inscribir(Estudiantes* e){
        inscribire.push_back(e);
    }

    void mostrarInscritos(){
        cout<<"assad de"<< asignaturas<<"tiene inscritos:\n";
        for(auto e : inscribire){
            cout<<"- "<<e->nombre<<endl;
        }
    }


    
};

class  Carrera{
private:
    Asignatura asigna;//composiones

public:
    string carrera;

    Carrera(){
        carrera = "Sin carrera";
    }

    Carrera(string car, Asignatura a) :  carrera(car), asigna(a){}
    
};


class Profesores : public Persona{ // Profesor con una clase posiblemente llamada curso es 1:1
public:
    string profesores;
    
    Profesores(){
        profesores = "Sin nombre";
    }

    Profesores(string pr) : profesores(pr){}
    void imparte(){
        
    }
};

class Estudiantes : public Persona{ // estudiantes y asignatura n:m
public:
    vector<Asignatura*> inscritos;

    Estudiantes() : Persona(){}

    
    Estudiantes(string n, string r, string c) :Persona(n,r,c){
        cout<<"persona creada\n"<<endl;
    }
    
    //inscribir
    

    //validacion

};

class Notas{
public:


};

class Mostrar_info{
public:


};


int main(){
    Estudiantes p1("caca","22084954-6","vicoco@gmail.com");
    p1.mostrar();


}




