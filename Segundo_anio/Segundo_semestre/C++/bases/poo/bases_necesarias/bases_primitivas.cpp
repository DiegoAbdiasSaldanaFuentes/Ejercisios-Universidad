#include <iostream>
#include <string>
using namespace std;

// ======================= CLASE LIBRO =======================

class Libro {
private:
    string titulo;
    string autor;
    int anio;

public:
    // Constructor por defecto
    Libro() : titulo("Sin titulo"), autor("Sin autor"), anio(0) {}

    // Constructor personalizado
    Libro(string t, string a, int an) : titulo(t), autor(a), anio(an) {}

    // Getters
    string getTitulo() const { return titulo; }
    string getAutor() const { return autor; }
    int getAnio() const { return anio; }

    // Metodo para mostrar información
    void mostrar() const {
        cout << "Titulo: " << titulo << endl;
        cout << "Autor : " << autor << endl;
        cout << "Anio  : " << anio << endl;
    }
};

// ======================= MAIN =======================

int main() {
    // Crear libro con valores por defecto
    Libro l1;
    cout << "--- Libro por defecto ---" << endl;
    l1.mostrar();

    cout << "\n";

    // Crear libro personalizado
    Libro l2("El Quijote", "Miguel de Cervantes", 1605);
    cout << "--- Libro personalizado ---" << endl;
    l2.mostrar();

    return 0;
}
