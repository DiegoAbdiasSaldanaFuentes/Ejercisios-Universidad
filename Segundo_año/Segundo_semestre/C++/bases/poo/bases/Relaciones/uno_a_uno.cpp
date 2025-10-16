#include <iostream>
using namespace std;

class Pasaporte {
public:
    string numero;
    Pasaporte(string n) : numero(n) {}
};

class Ciudadano {
public:
    string nombre;
    Pasaporte pasaporte; // 1 ciudadano -> 1 pasaporte / Composicion

    Ciudadano(string n, Pasaporte p) : nombre(n), pasaporte(p) {}  // como usamos composicion agregamos pasaporte al constructor
};

int main() {
    Pasaporte p("CHL123456");
    Ciudadano c("Diego", p);

    cout << c.nombre << " tiene el pasaporte " << c.pasaporte.numero << endl;
}

/*
- Ciudadano contiene un Pasaporte.
- Es una relacion uno a uno por composicion
- Si se destruye el ciudadano, tambien se destruye su Pasaporte
*/
