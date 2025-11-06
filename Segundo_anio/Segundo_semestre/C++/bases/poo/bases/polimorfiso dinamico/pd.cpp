#include <iostream>
using namespace std;

class Animal{
public:
    virtual void hablar(){
        cout << "El animal emite un sonido." << endl;
    }
};

class Perro : public Animal{
public:
    void hablar() override{
        cout << "Perro dice: Guau!" <<endl;
    }
};

class Humano : public Animal{
public:
    void hablar() override{
        cout << "Humano dice: Ya no hay buenos juegos en la play store :("<< endl;
    }
};

int main(){
    //Uso de polimorfismo normal
    Perro p;
    p.hablar(); // Se llama a la version de Perro


    Animal a;
    a.hablar(); // Se llama a la versión de Animal

    Humano h;
    h.hablar();
}