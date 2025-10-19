#include <iostream>
#include <vector>
using namespace std;

class Curso; // Declaración anticipada

class Estudiante {
public:
    string nombre;
    vector<Curso*> cursos;  // muchos cursos

    Estudiante(string n) : nombre(n) {}

    void inscribir(Curso* c);
};

class Curso {
public:
    string nombre;
    vector<Estudiante*> inscritos;  // muchos estudiantes

    Curso(string n) : nombre(n) {}

    void agregarEstudiante(Estudiante* e) {
        inscritos.push_back(e);
    }

    void mostrarInscritos() {
        cout << "Curso: " << nombre << endl;
        for (auto e : inscritos) {
            cout << " - " << e->nombre << endl;
        }
    }
};

// implementación después porque Curso fue declarado antes
void Estudiante::inscribir(Curso* c) {
    cursos.push_back(c);
    c->agregarEstudiante(this);
}

int main() {
    Estudiante e1("Hugo"), e2("Carla");
    Curso c1("Matemáticas"), c2("Física");

    e1.inscribir(&c1);
    e1.inscribir(&c2);
    e2.inscribir(&c2);

    c1.mostrarInscritos();
    c2.mostrarInscritos();
}
