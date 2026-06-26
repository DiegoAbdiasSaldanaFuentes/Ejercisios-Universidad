#include <iostream>
#include <vector>
#include <chrono>
#include <fstream> 
#include <string>  
#include <omp.h>

using namespace std;

struct Punto {
    uint64_t x;
    uint64_t y;
    Punto(uint64_t valX, uint64_t valY) : x(valX), y(valY) {}
};

Punto sumar_puntos(Punto P, Punto Q) {
    if (P.x == 0 && P.y == 0) return Q;
    if (Q.x == 0 && Q.y == 0) return P;

    uint64_t lambda;
    if (P.x == Q.x && P.y == Q.y) {
        if (P.y == 0) return Punto(0, 0); 
        lambda = (3 * P.x * P.x) / (2 * P.y); 
    } else {
        if (Q.x == P.x) return Punto(0, 0);
        lambda = (Q.y - P.y) / (Q.x - P.x); 
    }

    uint64_t nx = lambda * lambda - P.x - Q.x;
    uint64_t ny = lambda * (P.x - nx) - P.y;
    return Punto(nx, ny);
}

Punto multiplicacion_escalar(uint64_t k, Punto G) {
    Punto resultado(0, 0); 
    Punto actual(G.x, G.y);

    while (k > 0) {
        if (k & 1) resultado = sumar_puntos(resultado, actual);
        actual = sumar_puntos(actual, actual);
        k >>= 1;
    }
    return resultado;
}

int main(int argc, char* argv[]) {
    if (argc < 3) return 1;
    omp_set_num_threads(stoi(argv[2]));
    string modo = argv[1];

    Punto G(5, 1);
    uint64_t llave_privada = 123456; 
    Punto llave_publica = multiplicacion_escalar(llave_privada, G);
    uint64_t mascara = llave_publica.x; 

    ifstream inFile("input.txt");
    ofstream outFile("output.txt", ios::binary);
    if (!inFile || !outFile) return 1;

    string text((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());

    // Al usar una mascara XOR compartida, encriptar y desencriptar son matemáticamente idénticos.
    #pragma omp parallel for
    for (int i = 0; i < text.size(); ++i) {
        text[i] ^= (char)(mascara + i);
    }

    outFile << text;
    return 0;
}