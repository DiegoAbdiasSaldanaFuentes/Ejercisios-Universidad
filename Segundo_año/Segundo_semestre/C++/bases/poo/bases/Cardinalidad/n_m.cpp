#include <iostream>
#include <vector>
using namespace std;

class Estudiante{
public:
    string nombre;
    Estudiante(string n) : nombre(n){}
    
};


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