#include <iostream>
using namespace std;

class Persona{
private:
    int edad;
public:
    Persona(int e){
        edad = e; //asignacion normal
        cout<< "Persona  creada con edad "<< edad<<endl;

    }
};