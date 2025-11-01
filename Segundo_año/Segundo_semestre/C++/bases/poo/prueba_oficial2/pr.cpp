// Sistema academico
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

class Profesores;
class Carrera;
class Estudiantes;
class Asignatura;



class Persona{ 
private:
    string nombre;
    string rut;
    string correo;
public:
    Persona():nombre("Sin nombre"), rut ("Sin rut"), correo("Sin correo"){}
    Persona(string n, string r, string c) : nombre(n), rut(r), correo(c){}

    string getNombre() const { return nombre;}

    virtual void mostrar() const = 0;
    virtual ~Persona(){}
};

class Estudiantes : public Persona{ 
public:
    Estudiantes() : Persona(){}
    Estudiantes(string n, string r, string c) :Persona(n,r,c){}
    void mostrar() const override {
        cout << "Estudiante: " << getNombre() << endl;
    }
};

class Profesores : public Persona{ 
public:
    Profesores(string n, string r, string c) : Persona(n,r,c){}
    void mostrar() const override {
        cout << "Profesor: " << getNombre() << endl;
    }
};

class Asignatura{ // estudiantes y asignatura es n:m
private:
    int codigo;
    string nombreAsignaturas;
    int cupos;
    
public:
    Asignatura(): nombreAsignaturas("Sin asignatura"),codigo(0),cupos(0){}
    Asignatura(int c, string asig, int cup) : codigo(c), nombreAsignaturas(asig), cupos(cup){}
    vector<Estudiantes*> inscritos;
    vector<Profesores*> profesor;

    void inscribir(Estudiantes* e){
        if(inscritos.size() >= cupos){
            cout << "Cupo lleno en "<< nombreAsignaturas<<endl;
            return;
        }
        for(auto i: inscritos){
            if(i == e){
                cout<< e->getNombre() <<" ya esta inscrito en "<<nombreAsignaturas<<endl;
                return;
            }
        }
        inscritos.push_back(e);
        cout << e-> getNombre()<<" inscrito correctamente en "<<nombreAsignaturas<<endl;
    }

    void inscribir2(Profesores* p){
        profesor.push_back(p);
        cout<< p->getNombre()<<" imparte correctamente en "<<nombreAsignaturas<<endl;
    }
    void mostrarInscritos(){
        cout<<nombreAsignaturas<<"tiene inscritos:\n";
        for(auto e : inscritos){
            cout<<"- "<<e->getNombre()<<endl;
        }
    }
    void mostrarProfesor(){
        cout<<nombreAsignaturas<<"tiene al profesor:\n";
        for(auto p : profesor){
            cout<<"- "<<p->getNombre()<<endl;
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




class Notas{
public:


};

class Mostrar_info{
public:


}; 


int main(){
    // Crear asignaturas
    Asignatura poo(234, "Programacion Orientada a Objetos", 2);
    Asignatura bdd(221, "Bases de Datos", 2);
    // Crear estudiantes
    Estudiantes e1("Diego Saldana", "22.036.610-3", "diego@ucm.cl");
    // Crear profesor
    Profesores p1("Philip Vasquez","18.888.888-0","philip@bknucm.cl");
    // Mostrar estudiantes y profesores
    cout<<e1.getNombre()<<endl;
    cout<<p1.getNombre()<<endl;
    // Probar inscripcion

    
    poo.inscribir(&e1);
    cout << "\n--- Lista de inscritos ---\n";
    poo.mostrarInscritos();

    poo.inscribir2(&p1);
    cout<<"\n--Lista profesores impartiendo--\n";
    poo.mostrarProfesor();

    return 0;



}




