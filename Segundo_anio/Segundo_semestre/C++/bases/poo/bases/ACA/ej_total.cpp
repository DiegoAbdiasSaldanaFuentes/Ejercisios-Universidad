#include <iostream>
#include <vector>
using namespace std;

// Clase Motor (parte de Auto)
class Motor {
public:
    Motor() { cout << "Motor creado\n"; }
    ~Motor() { cout << "Motor destruido\n"; }
};

// Clase Auto que compone a Motor
class Auto {
private:
    Motor motor; // Composición
public:
    Auto() { cout << "Auto creado\n"; }
    ~Auto() { cout << "Auto destruido\n"; }
};

// Clase Estudiante
class Estudiante {
public:
    string nombre;
    Estudiante(string n) : nombre(n) {}
};

// Clase Curso que agrega estudiantes
class Curso {
private:
    vector<Estudiante*> inscritos; // Agregación
public:
    void inscribir(Estudiante* e) {
        inscritos.push_back(e);
    }
    void mostrar() {
        cout << "Inscritos:\n";
        for (auto e : inscritos)
            cout << "- " << e->nombre << endl;
    }
};

int main() {
    cout << "=== COMPOSICIÓN ===\n";
    {
        Auto a;  // al salir del bloque, motor y auto se destruyen juntos
    }
    
    cout << "\n=== AGREGACIÓN ===\n";
    Estudiante e1("Hugo"), e2("Carlos");
    Curso c;
    c.inscribir(&e1);
    c.inscribir(&e2);
    c.mostrar();
}
