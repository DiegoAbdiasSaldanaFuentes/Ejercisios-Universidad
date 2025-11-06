#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Persona;
class Estudiantes;
class Profesores;
class Asignatura;
class Carrera;
class Notas;




class Persona{ 
private:
    string nombre;
    string rut; 
    string correo;
public:
    Persona():nombre("Sin nombre"), rut ("Sin rut"), correo("Sin correo"){}
    Persona(string n, string r, string c) : nombre(n), rut(r), correo(c){}

    string getNombre() const { return nombre;}
    string getRut() const { return rut;}
    string getCorreo() const { return correo;}

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



class Asignatura{ 
private:
    int codigo; 
    string nombreAsignaturas;
    int cupos;
    
public:
    Asignatura(): nombreAsignaturas("Sin asignatura"),codigo(0),cupos(0){}
    Asignatura(int c, string asig, int cup) : codigo(c), nombreAsignaturas(asig), cupos(cup){}
    vector<Estudiantes*> inscritos;
    vector<Profesores*> profesor;

    string getAsignatura() const { return nombreAsignaturas;}
    int getCodigo() const { return codigo;}
    int getCupos() const { return cupos;}


    void inscribir(Estudiantes* e){
        if(inscritos.size() >= cupos){
            cout << "Lo sentimos "<<e->getNombre() <<" cupo lleno en "<< nombreAsignaturas<<endl;
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

    void inscribirProfesor(Profesores* p){
        profesor.push_back(p);
        cout<< p->getNombre()<<" imparte correctamente en "<<nombreAsignaturas<<endl;
    }

    void mostrarInscritos(){
        cout<<nombreAsignaturas<<" tiene inscritos:\n";
        for(auto e : inscritos){
            cout<<"- "<<e->getNombre()<<endl;
        }
    }
    void mostrarProfesor(){
        cout<<nombreAsignaturas<<" tiene al profesor:\n";
        for(auto p : profesor){
            cout<<"- "<<p->getNombre()<<endl;
        }
    }


    
};

class  Carrera{
private:
    string carrera;
    vector<Asignatura> asignaturas;
public:
    Carrera(): carrera("Sin carrera"){}
    Carrera(string car) :  carrera(car){}
    
    void agregarAsignatura(const Asignatura& a){
        asignaturas.push_back(a);
    }

    void mostrarAsignatura() const{
        cout<<"Carrera "<<carrera<<" Posee las siguientes asignaturas\n"<<endl;
        for(const auto& i : asignaturas){
            cout<<"- "<< i.getAsignatura() <<endl;
        }
    }
};





class Notas {
private:
    Estudiantes* estudiante;
    Asignatura* asignatura;
    vector<int> notas; 
public:
    Notas(Estudiantes* e, Asignatura* a) : estudiante(e), asignatura(a) {}

    void agregarNota(int n) {
        notas.push_back(n);
    }

    double calcularPromedio() const {
        if (notas.empty())
            return 0;
        double suma = 0;
        for (int n : notas)
            suma += n;
        return suma / notas.size(); 
    }

    void mostrarNotas() const {
        cout << "Notas de " << estudiante->getNombre() << " en " << asignatura->getAsignatura() << ": ";
        for (int n : notas)
            cout << n << " ";
        cout << "Promedio: " << calcularPromedio() << endl;
    }

    double getPromedio() const { return calcularPromedio(); }

    Estudiantes* getEstudiante() const { return estudiante; }

    Notas operator+(const Notas& otra) {
        Notas resultado(estudiante, asignatura);
        double promedio = (this->calcularPromedio() + otra.calcularPromedio()) / 2.0;
        resultado.agregarNota(promedio); 
        return resultado;
    }

    void mostrarPromedioTotal() const {
        cout << "Promedio combinado de " << estudiante->getNombre() << ": " << calcularPromedio() << endl;
    }
};


int main(){
    // Crear asignaturas
    Asignatura poo(234, "Programacion Orientada a Objetos", 2);
    Asignatura bdd(221, "Bases de Datos", 2);
    Asignatura ed(311,"Estructura de Datos",1);
    // Crear estudiantes
    Estudiantes e1("Diego Saldana", "22.036.610-3", "diego@ucm.cl");
    Estudiantes e2("Victor Farias","22.222.222-2","victor@ucm.cl");
    Estudiantes e3("Julian Martinez", "33.333.333-3","julian@ucm.cl");
    // Crear profesor
    Profesores p1("Philip Vasquez","8.888.888-0","philip@ucm.cl");
    Profesores p2("Hugo Araya","9.999.999-9","hugo@ucm.cl");
    Profesores p3("Carlos Castro","1.111.111-1","carlos@ucm.cl");
    // Mostrar estudiantes y profesores
    cout<<"\n--Lista personas creadas--\n";
    // Estudiantes
    cout<<e1.getNombre()<<endl;
    cout<<e2.getNombre()<<endl;
    cout<<e3.getNombre()<<endl;
    // Profesores
    cout<<p1.getNombre()<<endl;
    cout<<p2.getNombre()<<endl;
    cout<<p3.getNombre()<<endl;

    cout<<"\n";
    // Crear carrera
    Carrera c1("Ingenieria Civil Informatica");
    c1.agregarAsignatura(poo);
    c1.agregarAsignatura(bdd);
    c1.agregarAsignatura(ed);
    c1.mostrarAsignatura();
    
    
    cout << "\n-- Lista de estudiantes inscritos --\n";
    // Estudiantes inscritos
    poo.inscribir(&e1);
    poo.inscribir(&e2);
    poo.inscribir(&e3);
    ed.inscribir(&e1);
    ed.inscribir(&e2);
    ed.inscribir(&e3);
    bdd.inscribir(&e2);
    bdd.inscribir(&e2);
    bdd.inscribir(&e3);
    cout<<("\n");
    poo.mostrarInscritos();
    //Profesores inscritos
    cout<<"\n-- Lista profesores impartiendo --\n";
    poo.inscribirProfesor(&p1);
    ed.inscribirProfesor(&p2);
    bdd.inscribirProfesor(&p3);
    cout<<("\n");
    ed.mostrarProfesor();
    poo.mostrarProfesor();
    bdd.mostrarProfesor();

    // Crear notas
    //Notas inscritas
    cout << "\n-- Lista de notas --\n";
    // Notas Diego
    Notas n1(&e1, &poo);
    n1.agregarNota(60);
    n1.agregarNota(70);

    Notas n2(&e1, &bdd);
    n2.agregarNota(50);
    n2.agregarNota(60);

    n1.mostrarNotas();
    n2.mostrarNotas();

    // Notas Victor
    Notas n3(&e2, &ed);
    n3.agregarNota(40);
    n3.agregarNota(70);

    Notas n4(&e2, &bdd);
    n4.agregarNota(30);
    n4.agregarNota(40);

    n3.mostrarNotas();
    n4.mostrarNotas();


    cout << "\n-- Promedio final --\n";
    Notas promedioFinal1 = n1 + n2;   
    Notas promedioFinal2 = n3 + n4;   
    promedioFinal1.mostrarPromedioTotal();
    promedioFinal2.mostrarPromedioTotal();
    
    return 0;



}




