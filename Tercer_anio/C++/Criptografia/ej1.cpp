#include <iostream>
#include <cmath>
#include <chrono>

/**
 * Ejercicio: Demostración de la asimetría computacional.
 * Objetivo: Entender por qué la factorización protege los sistemas.
 */

bool es_primo(uint64_t n) {
    if (n <= 1) return false;
    for (uint64_t i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    // Paso 1: "Simulamos" la creación de una clave pública 
    // Usamos primos medianos para que tu PC no explote, pero nota la diferencia.
    uint64_t p = 104729; 
    uint64_t q = 15485864;
    uint64_t n = p * q;

    std::cout << "--- Generacion de 'Clave' ---" << std::endl;
    std::cout << "Producto n (p*q): " << n << "\n\n";

    // Paso 2: El reto del atacante (Factorización) [cite: 29, 30]
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