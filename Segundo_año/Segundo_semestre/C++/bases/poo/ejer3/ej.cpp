#include <iostream>
#include <vector>
using namespace std;

class Estudiante{
public:
    string nombre_es;
    int matricula;
    float promedio;
    Estudiante(){
        nombre_es = "Sin nombre";
        matricula = 0;
        promedio = 0.0;
    }
    Estudiante(string n, int ma, float pro) : nombre_es(n), matricula(ma), promedio(pro){}

    
};

class Profesores{
public:
    string nombre_pr;
    int numero_empleado;
    string especialidad;
    Profesores(){
        nombre_pr = "Sin nombre";
        numero_empleado = 0;
        especialidad = "Ninguna";
    }
    Profesores(string nom, int num_emp, string esp) : nombre_pr(nom), numero_empleado(num_emp), especialidad(esp){}

};



class Cursos{ // Un curso tiene  un profesor y varios estudiantes. Enfasis en los "tiene" lo que lleva a hacer composición
public:

    string nombre_curso;
    int codigo;
    Profesores profesor; // composicion
    vector<Estudiante*> inscritos; // agregacion
    Cursos(string nom, int cod, Profesores p)
        : nombre_curso(nom), codigo(cod), profesor(p) {}


    void inscribir(Estudiante* e){
        inscritos.push_back(e);
    }
    void mostrarInscritos(){
        cout << "Curso "<<  nombre_curso << " tiene  inscritos: \n";
        for(auto e : inscritos){
            cout << "-" << e -> nombre_es<< endl;
        }
    }
};


int main() {
    // Crear profesor
    Profesores prof1("Juan Morales", 1001, "Matemáticas");

    // Crear estudiantes
    Estudiante e1("Hugo", 1, 2.0);
    Estudiante e2("Carla", 2, 3.5);
    Estudiante e3("Luis", 3, 4.2);

    // Crear curso y asignar profesor
    Cursos curso1("Algebra", 101, prof1);

    // Inscribir estudiantes
    curso1.inscribir(&e1);
    curso1.inscribir(&e2);
    curso1.inscribir(&e3);

    // Mostrar los inscritos
    curso1.mostrarInscritos();

    return 0;
}
