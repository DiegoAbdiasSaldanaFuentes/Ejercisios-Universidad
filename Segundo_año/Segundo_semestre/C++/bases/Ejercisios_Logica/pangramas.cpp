#include <iostream>
#include <string>
#include <cctype> // para tolower

using namespace std;

bool esPangrama(const string& frase) {
    bool letras[26] = {false}; // Inicializamos todas las letras como no encontradas

    for (char c : frase) {
        if (isalpha(c)) { // solo letras
            int indice = tolower(c) - 'a';
            letras[indice] = true;
        }
    }

    // Verificar si todas las letras aparecieron
    for (int i = 0; i < 26; i++) {
        if (!letras[i]) return false; // alguna letra falta
    }

    return true;
}

int main() {
    string frase;
    cout << "Ingresa una frase: ";
    getline(cin, frase); // para leer toda la línea, incluyendo espacios

    if (esPangrama(frase)) {
        cout << "SI" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
