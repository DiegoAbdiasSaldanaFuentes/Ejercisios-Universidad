#include <iostream>
#include <string>
using namespace std;

class Profesor {
public:
    string nombre;
};

class Curso {
public:
    string nombre;
    Profesor* profesor; // Asociación (puntero, no propiedad)
};
