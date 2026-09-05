#include <iostream>
#include <chrono>
#include <vector>
#include <omp.h> // Librería fundamental para controlar los hilos

using namespace std;
using namespace std::chrono;

// Función de Exponenciación Modular
long long modExp(long long base, long long exp, long long mod) {
    long long res = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) 
            res = (res * base) % mod;
        exp = exp >> 1; 
        base = (base * base) % mod;
    }
    return res;
}

// Función auxiliar para imprimir tiempos
void printTime(const string& label, long long time_us) {
    cout << label;
    if (time_us < 1000) {
        cout << time_us << " microsegundos (us)." << endl;
    } else {
        cout << (time_us / 1000.0) << " milisegundos (ms)." << endl;
    }
}

// Función que empaqueta el test para correrlo con distintos hilos
void runBenchmark(int num_threads, int iterations, long long message, long long e, long long d, long long n) {
    cout << "\n=== EJECUTANDO CON " << num_threads << " HILO(S) ===" << endl;
    
    // Le decimos a OpenMP cuántos hilos usar en esta pasada
    omp_set_num_threads(num_threads);

    // Creamos arreglos para evitar que los hilos choquen entre sí
    vector<long long> encrypted_msgs(iterations);
    vector<long long> decrypted_msgs(iterations);

    // --- ENCRIPTACIÓN ---
    auto start_enc = high_resolution_clock::now();
    
    #pragma omp parallel for // ¡Esta línea reparte el bucle entre los hilos!
    for(int i = 0; i < iterations; i++) {
        encrypted_msgs[i] = modExp(message, e, n); 
    }
    
    auto end_enc = high_resolution_clock::now();
    auto duration_enc_us = duration_cast<microseconds>(end_enc - start_enc).count();

    // --- DESENCRIPTACIÓN ---
    auto start_dec = high_resolution_clock::now();
    
    #pragma omp parallel for
    for(int i = 0; i < iterations; i++) {
        decrypted_msgs[i] = modExp(encrypted_msgs[i], d, n);
    }
    
    auto end_dec = high_resolution_clock::now();
    auto duration_dec_us = duration_cast<microseconds>(end_dec - start_dec).count();

    // --- RESULTADOS ---
    printTime("Tiempo Encriptacion:    ", duration_enc_us);
    printTime("Tiempo Desencriptacion: ", duration_dec_us);
    printTime("Tiempo TOTAL CPU:       ", duration_enc_us + duration_dec_us);
}

int main() {
    cout << "--- BENCHMARK RSA MULTI-NUCLEO ---" << endl;

    long long p = 61, q = 53;
    long long n = p * q;                  
    long long e = 17;                     
    long long d = 2753;                   
    long long message = 65;               
    
    // Subimos la carga para que los hilos realmente tengan trabajo que hacer
    int iterations = 100000000;             
    cout << "Carga de trabajo: " << iterations << " operaciones por fase." << endl;

    // Ejecutamos las 3 pruebas
    runBenchmark(20, iterations, message, e, d, n);  // Sin paralelismo (Baseline)
    runBenchmark(6, iterations, message, e, d, n);  // Mitad de hilos lógicos
    runBenchmark(12, iterations, message, e, d, n); // Todos los hilos al 100%

    return 0;
}