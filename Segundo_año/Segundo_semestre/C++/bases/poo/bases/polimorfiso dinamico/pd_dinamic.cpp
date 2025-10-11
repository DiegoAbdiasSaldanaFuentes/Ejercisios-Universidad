#include <iostream>
using namespace std;

class Animal{
public:
    virtual void hablar(){
        cout << "El animal emite un sonido." <<endl;
    }
};

class Gato : public Animal{
public:
    void hablar() override{
        cout << "El gato dice: Miau!" <<endl;
    }
};

class Pato : public Animal{
public:
    void hablar() override{
        cout <<"El pato dice: cuack!" <<endl;
    }
};

int main(){
    /*El puntero Animal* apunta a un Gato. Al llamar a hablar(), se ejecuta ña version de Gato, no la de Animal, gracias a virtual*/
    Animal* a = new Gato();
    a -> hablar(); // Salida: gato dice: Miau!
    delete a;

    Animal* b = new Pato();
    b -> hablar();
    delete b;
}