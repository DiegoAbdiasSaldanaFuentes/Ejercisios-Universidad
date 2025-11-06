#include <iostream>
using namespace std;

class Figura{
public:
    virtual void dibujar() const = 0; //Metodo abstracto, uso de const para que no modifique el estado del objeto
};

class Circulo : public Figura {
public:
    void dibujar() const override{
        cout << "Dibujando un circulo" <<endl;
    }
};

class Cuadrado : public Figura {
public:
    void dibujar() const override{
        cout << "Dibujando un cuadrado" << endl;
    }
};

int main(){
    Figura* f1 = new Circulo();
    Figura* f2 = new Cuadrado();

    f1 ->dibujar(); // Polimorfismo real/dinamico
    f2 ->dibujar();

    delete f1;
    delete f2;
    return 0;
}