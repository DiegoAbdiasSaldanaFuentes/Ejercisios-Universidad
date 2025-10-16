#include <iostream>
#include <vector>
using namespace std;

class Estudiante{
public:
    string nombre_es;
    int matricula;
    float promedio;
    Estudiante(string n, int ma, float pro) : nombre(n), matricula(ma), promedio(pro){}

    
};

class Profesores{
public:
    string nombre;
    int numero_empleado;
    string especialidad;
    Profesores(string nom, int num_emp, string esp) : nombre(nom), numero_empleado(num_emp), especialidad(esp){}

};



class Cursos{
public:
    string nombre;
    int codigo;
    vector<Estudiante*> inscritos;
    Cursos(string nom, int cod) : nombre(nom), codigo(cod){}

    void inscribir(Estudiante* e){
        inscritos.push_back(e);
    }
    void mostrarInscritos(){
        cout << "Estudiante "<<     << " tiene  inscritos: \n";
        for(auto e : inscritos){
            cout << "-" << e -> nombre<< endl;
        }
    }
};

/* 
class Taller{
public:
    string tema;
    vector<Estudiante*> inscritos;

    Taller(string t) :  tema(t){}

    void inscribir(Estudiante* e){
        inscritos.push_back(e);
    }

    void mostrarInscritos(){
        cout << "Taller de "<< tema<< " tiene  inscritos: \n";
        for(auto e : inscritos){
            cout << "-" << e -> nombre<< endl;
        }
    }
};
*/

int main(){
    Estudiante e1 ("Hugo"), e2("Carlitos"), e3("Philip");

    Taller robotica("ROBOTICA");
    Taller ia("Inteligencia Artificial");

    robotica.inscribir(&e1);
    robotica.inscribir(&e2);
    ia.inscribir(&e2);
    ia.inscribir(&e3);

    robotica.mostrarInscritos();
    ia.mostrarInscritos();
}