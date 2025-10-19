#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Estudiante {};

class Curso {
private:
    vector<Estudiante*> inscritos; // Agregación (punteros o referencias)
};
