/**
 * Codigo de ejemplo de solución
 * 
 * 
 * 
 * 
 * 
 * 
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype> // para std::tolower

// Función para limpiar y normalizar una cadena
std::string normalizar(const std::string& cadena) {
    std::string limpia;

    for (char c : cadena) {
        if (!std::isspace(c)) { // ignorar espacios
            limpia += std::tolower(c); // pasar a minúscula
        }
    }

    std::sort(limpia.begin(), limpia.end()); // ordenar
    return limpia;
}

// Función para verificar si dos cadenas son anagramas
bool sonAnagramas(const std::string& a, const std::string& b) {
    return normalizar(a) == normalizar(b);
}

int main() {
    std::string palabra1, palabra2;

    std::cout << "Ingresa la primera palabra o frase: ";
    std::getline(std::cin, palabra1);

    std::cout << "Ingresa la segunda palabra o frase: ";
    std::getline(std::cin, palabra2);

    if (sonAnagramas(palabra1, palabra2)) {
        std::cout << "Son anagramas." << std::endl;
    } else {
        std::cout << "No son anagramas." << std::endl;
    }

    return 0;
}
