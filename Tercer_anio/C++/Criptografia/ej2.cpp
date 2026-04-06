#include <iostream>
#include <thread>
#include <vector>
#include <atomic>
#include <mutex>
#include <chrono> // Para el temporizador [cite: 14]

std::atomic<bool> encontrado(false);
std::mutex mtx_salida;
uint64_t llave_final = 0;

// Simulación de búsqueda de escalar en Curva Elíptica
void buscar_k(uint64_t inicio, uint64_t fin, uint64_t objetivo) {
    for (uint64_t k = inicio; k < fin && !encontrado; ++k) {
        if (k == objetivo) { 
            encontrado = true;
            std::lock_guard<std::mutex> lock(mtx_salida);
            llave_final = k;
        }
    }
}

int main() {
    // Configuración para tu HP Victus [cite: 30]
    const uint64_t OBJETIVO = 950000000; 
    const uint64_t RANGO_MAX = 1000000000;
    const int HILOS = 20; 
    uint64_t segmento = RANGO_MAX / HILOS;

    std::vector<std::thread> pool;

    std::cout << "Iniciando busqueda en 20 hilos..." << std::endl;

    // --- INICIO DEL TEMPORIZADOR ---
    auto inicio_reloj = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < HILOS; ++i) {
        uint64_t inicio = i * segmento;
        uint64_t fin = (i == HILOS - 1) ? RANGO_MAX : (i + 1) * segmento;
        pool.emplace_back(buscar_k, inicio, fin, OBJETIVO);
    }

    for (auto& t : pool) {
        t.join();
    }

    // --- FIN DEL TEMPORIZADOR ---
    auto fin_reloj = std::chrono::high_resolution_clock::now();
    
    // Cálculo de duración
    std::chrono::duration<double> duracion = fin_reloj - inicio_reloj;

    if (encontrado) {
        std::cout << "[EXITO] Llave encontrada: " << llave_final << std::endl;
    }
    
    std::cout << "Tiempo total de ejecucion: " << duracion.count() << " segundos." << std::endl;

    return 0;
}