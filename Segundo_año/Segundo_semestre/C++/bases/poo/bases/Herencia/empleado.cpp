#include <iostream>
#include <string>
using namespace std;
//Version sin constructor
class Empleado{
public:
    string nombre;
    void trabajar(){
        cout << nombre << " esta trabajando."<<endl;
    }
};

class Gerente : public Empleado{
public:
    void supervisar(){
        cout << nombre << " esta supervisando."<< endl;
    }
};

int main(){
    Gerente g;
    g.nombre = "Ana";
    g.trabajar(); //Heredado
    g.supervisar(); //Propio Gerente
};
