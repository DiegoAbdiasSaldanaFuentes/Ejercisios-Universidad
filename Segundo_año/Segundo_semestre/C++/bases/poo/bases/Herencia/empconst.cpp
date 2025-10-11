#include <iostream>
#include <string>
using namespace std;
//Version sin constructor
class Empleado{
public:
    Empleado(string nombre){
        cout<< "Constructor Empleado: "<< nombre << endl;
    }
};

class Gerente : public Empleado{
public:
    Gerente(string nombreG): Empleado(nombreG){
        cout << "Constructor Gerente: "<< nombreG<<endl;
    } 
};

int main(){
    Empleado a("Diego");
    Gerente b("Diego");
};
