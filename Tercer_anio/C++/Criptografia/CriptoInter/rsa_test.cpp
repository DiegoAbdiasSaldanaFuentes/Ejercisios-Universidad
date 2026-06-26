#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <omp.h> // Librería de hilos

using namespace std;

// Función de Exponenciación Modular RSA
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

// Ahora el main recibe argumentos desde Python (ej: -e 12)
int main(int argc, char *argv[]) {
    // Verificar que Python nos mandó el modo y los hilos
    if (argc < 3) {
        cerr << "Error: Faltan argumentos. Uso: rsa.exe [-e / -d] [num_hilos]" << endl;
        return 1;
    }

    string modo = argv[1]; // "-e" o "-d"
    int num_threads = stoi(argv[2]); // Cantidad de hilos desde la interfaz
    omp_set_num_threads(num_threads);

    // Claves RSA
    long long p = 61, q = 53;
    long long n = p * q;                  
    long long e = 17;                     
    long long d = 2753;                   

    if (modo == "-e") {
        // ==========================================
        // MODO ENCRIPTAR
        // ==========================================
        ifstream archivo_in("input.txt");
        if (!archivo_in.is_open()) return 1;

        // Leer todo el texto legible
        stringstream buffer;
        buffer << archivo_in.rdbuf();
        string texto_original = buffer.str();
        archivo_in.close();

        int longitud = texto_original.length();
        vector<long long> texto_encriptado(longitud);

        // Paralelismo: Cada hilo toma una letra y la encripta
        #pragma omp parallel for
        for (int i = 0; i < longitud; i++) {
            texto_encriptado[i] = modExp((long long)texto_original[i], e, n);
        }

        // Guardar los números gigantes en output.txt
        ofstream archivo_out("output.txt");
        for (int i = 0; i < longitud; i++) {
            archivo_out << texto_encriptado[i] << " ";
        }
        archivo_out.close();

    } else if (modo == "-d") {
        // ==========================================
        // MODO DESENCRIPTAR
        // ==========================================
        ifstream archivo_in("input.txt");
        if (!archivo_in.is_open()) return 1;

        // Leer los números gigantes separados por espacios
        vector<long long> numeros_encriptados;
        long long numero_leido;
        while (archivo_in >> numero_leido) {
            numeros_encriptados.push_back(numero_leido);
        }
        archivo_in.close();

        int longitud = numeros_encriptados.size();
        string texto_desencriptado(longitud, ' '); // Crear string con tamaño exacto

        // Paralelismo: Cada hilo toma un número y lo convierte a letra
        #pragma omp parallel for
        for (int i = 0; i < longitud; i++) {
            texto_desencriptado[i] = (char)modExp(numeros_encriptados[i], d, n);
        }

        // Guardar el texto legible en output.txt
        ofstream archivo_out("output.txt");
        archivo_out << texto_desencriptado;
        archivo_out.close();

    } else {
        cerr << "Error: Modo no reconocido (" << modo << ")." << endl;
        return 1;
    }

    return 0; // Si todo sale bien, C++ termina silenciosamente y Python lee el archivo
}