#include <iostream>
using namespace std;

class Persona{
private:
    int edad;
    int peso;
public:
    Persona(int e, int pes) : edad(e){
        cout<< "Persona  creada con edad "<< edad<<endl;
    }
};