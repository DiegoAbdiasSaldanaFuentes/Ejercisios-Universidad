#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>

std::mutex mtx_terminal;

struct Punto {
    uint64_t* x;
    uint64_t* y;

    Punto(uint64_t valX, uint64_t valY) {
        x = new uint64_t(valX);
        y = new uint64_t(valY);
    }

    ~Punto() {
        delete x;
        delete y;
    }
};

// ARITMÉTICA DE CURVA ELÍPTICA (secp256k1: y^2 = x^3 + 7) 

Punto* sumar_puntos(const Punto* P, const Punto* Q) {
    if (*P->x == 0 && *P->y == 0) return new Punto(*Q->x, *Q->y);
    if (*Q->x == 0 && *Q->y == 0) return new Punto(*P->x, *P->y);

    uint64_t lambda;
    if (*P->x == *Q->x && *P->y == *Q->y) {
        // Evitar división por cero si y es 0
        if (*P->y == 0) return new Punto(0, 0); 
        lambda = (3 * (*P->x) * (*P->x)) / (2 * (*P->y)); 
    } else {
        // Evitar división por cero si x1 == x2
        if (*Q->x == *P->x) return new Punto(0, 0);
        lambda = (*Q->y - *P->y) / (*Q->x - *P->x); 
    }

    uint64_t nx = lambda * lambda - *P->x - *Q->x;
    uint64_t ny = lambda * (*P->x - nx) - *P->y;

    return new Punto(nx, ny);
}

Punto* multiplicacion_escalar(uint64_t k, const Punto* G) {
    Punto* resultado = new Punto(0, 0); 
    Punto* actual = new Punto(*G->x, *G->y);

    while (k > 0) {
        if (k & 1) {
            Punto* temp = sumar_puntos(resultado, actual);
            delete resultado;
            resultado = temp;
        }
        Punto* temp_doble = sumar_puntos(actual, actual);
        delete actual;
        actual = temp_doble;
        k >>= 1;
    }
    delete actual;
    return resultado;
}

void procesar_batch_ecc(int id, uint64_t escalar, const Punto* G) {
    Punto* llave_publica = multiplicacion_escalar(escalar, G);
    
    {
        std::lock_guard<std::mutex> lock(mtx_terminal);
        std::cout << "[Hilo " << id << "] Escalar: " << escalar 
                  << " -> Llave Publica: (" << *llave_publica->x 
                  << ", " << *llave_publica->y << ")" << std::endl;
    }
    
    delete llave_publica;
}

int main() {
    Punto* G = new Punto(5, 1);
    const int HILOS = 20;
    std::vector<std::thread> pool;

    std::cout << "--- INICIANDO SISTEMA ECC (Sincronizado) ---" << std::endl;
    std::cout << "Procesando " << HILOS << " hilos en paralelo..." << std::endl;
    std::cout << "--------------------------------------------" << std::endl;

    auto inicio = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < HILOS; ++i) {
        uint64_t llave_privada_simulada = 1000 + i; pool.emplace_back(procesar_batch_ecc, i, llave_privada_simulada, G);
    }

    for (auto& t : pool) t.join();

    auto fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracion = fin - inicio;

    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "Tiempo total de procesamiento ECC: " << duracion.count() << " segundos" << std::endl;

    delete G;
    return 0;
}