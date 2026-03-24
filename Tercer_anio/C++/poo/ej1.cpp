#include <iostream>
#include <string>

using namespace std;

class banco{
private:
    string nombre = "sin_nombre";
    int sueldo=0;
public:

    void set_atributos(string n, int s){
        nombre = n;
        sueldo = s;
    }



    string llamar_nombre(){
        return nombre;
    }
    
    int llamar_sueldo(){
        return sueldo;
    }
};



int main(){

    banco diego;
    diego.set_atributos("Diego",100000);
    cout<<diego.llamar_nombre()<<endl;
    cout<<diego.llamar_sueldo()<<endl;
}
