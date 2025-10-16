#include <iostream>
#include <vector>
using namespace std;

class Estudiante {
public:
    string nombre;
    Estudiante(string n) : nombre(n) {}
};

class Profesor {
public:
    string nombre;
    vector<Estudiante*> alumnos;  // 1 profesor -> N estudiantes

    Profesor(string n) : nombre(n) {}

    void agregarAlumno(Estudiante* e) {
        alumnos.push_back(e);
    }

    void mostrarAlumnos() {
        cout << "Profesor " << nombre << " enseña a:\n";
        for (auto e : alumnos) {
            cout << " - " << e->nombre << endl;
        }
    }
};

int main() {
    Estudiante e1("Hugo"), e2("Carla"), e3("Philip");

    Profesor p("Rodriguez");
    p.agregarAlumno(&e1);
    p.agregarAlumno(&e2);
    p.agregarAlumno(&e3);

    p.mostrarAlumnos();
}
