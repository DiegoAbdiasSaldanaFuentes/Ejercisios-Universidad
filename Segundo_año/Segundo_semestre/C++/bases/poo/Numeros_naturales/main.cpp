#include <iostream>
#include <vector>
#include "Numeros.h"   // Incluimos tu clase

using namespace std;

int main() {
    // 1) Crear objeto con valor inicial
    Numeros_naturales n(10);  // Valor = 10
    cout << "Valor inicial: " << n.getValor() << endl;

    // 2) Probar SUMA
    n.Suma(5);    // 10 + 5 = 15
    cout << "Resultado tras suma: " << n.Suma() << endl;

    // 3) Probar RESTA
    n.Resta(3);   // 15 - 3 = 12
    cout << "Resultado tras resta: " << n.Resta() << endl;

    // 4) Probar MULTIPLICACION
    n.Multiplicacion(2);   // 12 * 2 = 24
    cout << "Resultado tras multiplicacion: " << n.Multiplicacion() << endl;

    // 5) Probar DIVISION
    try {
        n.Division(4);     // 24 / 4 = 6
        cout << "Resultado tras division: " << n.Division() << endl;
    } catch (const runtime_error& e) {
        cout << "Error en division: " << e.what() << endl;
    }

    // 6) Probar esPar y esPrimo
    cout << "El valor actual (" << n.getValor() << ") es par? "
         << (n.esPar() ? "Si" : "No") << endl;

    cout << "El valor actual (" << n.getValor() << ") es primo? "
         << (n.esPrimo() ? "Si" : "No") << endl;

    // 7) Probar COLLATZ
    cout << "Secuencia de Collatz desde " << n.getValor() << ": ";
    vector<int> secuencia = n.Collatz();
    for (int v : secuencia) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
