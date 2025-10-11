#include <iostream>
#include <string>
using namespace std;

class Coche{
private:
    string modelo;
public:
    Coche(string m){
        modelo = m;
    }

    void arrancar() const{
        cout << "El coche " << modelo << " esta arrancando. " <<endl;
    }

    void detener() const {
        cout << "El coche "<< modelo << " se ha detenido. "<< endl;
    }
};

class Persona{
private:
    string nombre;
public:
    Persona(string n){
        nombre = n;
    }
    //Persona depende conducir de la clase Coche
    void conducir(const Coche& coche){// se pasa parametro por valor ya que ocupa menos memoria
        cout << nombre << " empieza a conducir."<< endl;
        coche.arrancar();
        cout << nombre << " está manejando"<< endl;
        coche.detener();
        cout<< nombre << " termino de conducir"<< endl;
    }
};

int main(){
    Coche miCoche("Ford Raptor");
    Persona p("Diego");

    p.conducir(miCoche);

    return 0;
}
