#include <iostream>
#include <thread>
#include <vector>
#include <atomic>
#include <mutex>
#include <chrono>
#include <cmath> 

std::atomic<bool> encontrado(false);
std::mutex mtx_salida;
uint64_t llave_final = 0;


bool es_primo(uint64_t n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (uint64_t i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

void buscar_llave_cripto(uint64_t inicio, uint64_t fin, uint64_t SECRETO_HASHEADO) {
    for (uint64_t k = inicio; k < fin && !encontrado; ++k) {
 
        if (k == SECRETO_HASHEADO) { 
            if (es_primo(k)) { // Verificamos si es primo
                encontrado = true;
                std::lock_guard<std::mutex> lock(mtx_salida);
                llave_final = k;
            }
        }
    }
}

int main() {

    const uint64_t LLAVE_A_BUSCAR = 950000017; //  primo grande
    const uint64_t RANGO_MAX = 1000000000;
    const int HILOS = 20; 
    
    uint64_t segmento = RANGO_MAX / HILOS;
    std::vector<std::thread> pool;

    std::cout << "Iniciando ataque de fuerza bruta (Simulacion ECC) " << std::endl;
    std::cout << "Buscando llave en rango de " << RANGO_MAX << " con " << HILOS << " hilos" << std::endl;

    auto inicio_reloj = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < HILOS; ++i) {
        uint64_t inicio = i * segmento;
        uint64_t fin = (i == HILOS - 1) ? RANGO_MAX : (i + 1) * segmento;
        pool.emplace_back(buscar_llave_cripto, inicio, fin, LLAVE_A_BUSCAR);
    }

    for (auto& t : pool) {
        t.join(); 
    }

    auto fin_reloj = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracion = fin_reloj - inicio_reloj;

    if (encontrado) {
        std::cout << "Llave criptografica encontrada: " << llave_final << std::endl;
        std::cout << "El numero es un primo valido para el sistema." << std::endl;
    } else {
        std::cout << "No se encontro la llave en el rango especificado" << std::endl;
    }
    
    std::cout << "Tiempo de calculo: " << duracion.count() << " segundos" << std::endl;
    return 0;
}