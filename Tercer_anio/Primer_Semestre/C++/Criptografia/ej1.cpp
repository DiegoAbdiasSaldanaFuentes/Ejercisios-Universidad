#include <iostream>
#include <cmath>
#include <chrono>


int main() {

    uint64_t p = 104729; 
    uint64_t q = 15485863;
    uint64_t n = p * q;

    std::cout << "--- Generacion de 'Clave' ---" << std::endl;
    std::cout << "Producto n (p*q): " << n << "\n\n";


    std::cout << "Iniciando ataque de factorizacion..." << std::endl;
    auto start = std::chrono::high_resolution_clock::now();

    for (uint64_t i = 2; i <= n; i++) {
        if (n % i == 0) {
            std::cout << "Factor encontrado: " << i << " (y " << n/i << ")" << std::endl;
            break; 
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Tiempo de calculo: " << diff.count() << " segundos." << std::endl;

    return 0;
}