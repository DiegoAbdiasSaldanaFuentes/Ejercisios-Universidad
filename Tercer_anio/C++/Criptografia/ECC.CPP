#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>
#include <fstream> 
#include <string>  

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

// ARITMETICA DE CURVA ELIPTICA (secp256k1: y^2 = x^3 + 7) 

Punto* sumar_puntos(const Punto* P, const Punto* Q) {
    if (*P->x == 0 && *P->y == 0) return new Punto(*Q->x, *Q->y);
    if (*Q->x == 0 && *Q->y == 0) return new Punto(*P->x, *P->y);

    uint64_t lambda;
    if (*P->x == *Q->x && *P->y == *Q->y) {
        if (*P->y == 0) return new Punto(0, 0); 
        lambda = (3 * (*P->x) * (*P->x)) / (2 * (*P->y)); 
    } else {
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

void ejecutar_cifrado_archivo(const Punto* G, uint64_t llave_privada) {
    Punto* llave_publica = multiplicacion_escalar(llave_privada, G);
    uint64_t mascara = *llave_publica->x; 

    std::ifstream archivo_entrada("input_ecc.txt");
    if (!archivo_entrada.is_open()) {
        std::cerr << "Error: No se pudo abrir input_ecc.txt. Crea el archivo con texto primero." << std::endl;
        delete llave_publica;
        return;
    }

    std::string texto_plano;
    std::getline(archivo_entrada, texto_plano);
    archivo_entrada.close();

    std::cout << "[ECC] Texto leido de input_ecc.txt: " << texto_plano << std::endl;

    auto inicio_cifrado = std::chrono::high_resolution_clock::now();
    std::string texto_cifrado = texto_plano;
    for (size_t i = 0; i < texto_plano.size(); ++i) {
        texto_cifrado[i] = texto_plano[i] ^ (char)(mascara + i); 
    }
    auto fin_cifrado = std::chrono::high_resolution_clock::now();

    std::ofstream archivo_salida("output_ecc.txt", std::ios::binary);
    archivo_salida << texto_cifrado;
    archivo_salida.close();
    std::cout << "[ECC] Texto encriptado guardado en output_ecc.txt" << std::endl;

    auto inicio_descifrado = std::chrono::high_resolution_clock::now();
    std::string texto_descifrado = texto_cifrado;
    
    Punto* secreto_recuperado = multiplicacion_escalar(llave_privada, G);
    uint64_t mascara_descifrado = *secreto_recuperado->x;

    for (size_t i = 0; i < texto_cifrado.size(); ++i) {
        texto_descifrado[i] = texto_cifrado[i] ^ (char)(mascara_descifrado + i);
    }
    auto fin_descifrado = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> tiempo_cifrado = fin_cifrado - inicio_cifrado;
    std::chrono::duration<double, std::milli> tiempo_descifrado = fin_descifrado - inicio_descifrado;

    std::cout << "\n================= RESULTADOS METRICAS =================" << std::endl;
    std::cout << "Llave Publica utilizada: (" << *llave_publica->x << ", " << *llave_publica->y << ")" << std::endl;
    std::cout << "Texto desencriptado con exito: " << texto_descifrado << std::endl;
    std::cout << "Tiempo de Encriptacion: " << tiempo_cifrado.count() << " ms" << std::endl;
    std::cout << "Tiempo de Desencriptacion: " << tiempo_descifrado.count() << " ms" << std::endl;
    std::cout << "=======================================================\n" << std::endl;

    delete llave_publica;
    delete secreto_recuperado;
}

void procesar_batch_ecc(int id, uint64_t determinar, const Punto* G) {
    Punto* llave_publica = multiplicacion_escalar(determinar, G);
    
    {
        std::lock_guard<std::mutex> lock(mtx_terminal);
        std::cout << "[Hilo " << id << "] Escalar: " << determinar 
                  << " -> Llave Publica: (" << *llave_publica->x 
                  << ", " << *llave_publica->y << ")" << std::endl;
    }
    
    delete llave_publica;
}

int main() {
    Punto* G = new Punto(5, 1);
    const int HILOS = 1;
    std::vector<std::thread> pool;

    std::cout << "--- INICIANDO SISTEMA ECC (Sincronizado) ---" << std::endl;
    std::cout << "Procesando " << HILOS << " hilos en paralelo..." << std::endl;
    std::cout << "--------------------------------------------" << std::endl;

    auto inicio = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < HILOS; ++i) {
        uint64_t llave_privada_simulada = 1000 + i; 
        pool.emplace_back(procesar_batch_ecc, i, llave_privada_simulada, G);
    }

    for (auto& t : pool) t.join();

    auto fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracion = fin - inicio;

    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "Tiempo total de procesamiento de hilos: " << duracion.count() << " segundos\n" << std::endl;

    std::cout << "--- INICIANDO CIFRADO/DESCIFRADO DE ARCHIVOS ---" << std::endl;
    uint64_t llave_privada_maestra = 123456; 
    ejecutar_cifrado_archivo(G, llave_privada_maestra);

    delete G;
    return 0;
}