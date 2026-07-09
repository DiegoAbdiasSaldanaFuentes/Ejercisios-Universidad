#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdint>

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

void procesar_archivo(const std::string& input_file, const std::string& output_file, const Punto* G, uint64_t llave) {
    Punto* llave_generada = multiplicacion_escalar(llave, G);
    uint64_t mascara = *llave_generada->x;

    std::ifstream archivo_entrada(input_file, std::ios::binary | std::ios::ate);
    if (!archivo_entrada.is_open()) {
        delete llave_generada;
        return;
    }

    std::streamsize size = archivo_entrada.tellg();
    archivo_entrada.seekg(0, std::ios::beg);
    std::vector<char> buffer(size);
    
    if (!archivo_entrada.read(buffer.data(), size)) {
        delete llave_generada;
        return;
    }
    archivo_entrada.close();

    for (std::streamsize i = 0; i < size; ++i) {
        buffer[i] = buffer[i] ^ (char)(mascara + i);
    }

    std::ofstream archivo_salida(output_file, std::ios::binary);
    archivo_salida.write(buffer.data(), size);
    archivo_salida.close();

    delete llave_generada;
}

int main(int argc, char* argv[]) {
    if(argc < 4) return 1;

    std::string modo = argv[1];
    uint64_t clave;
    
    try {
        clave = std::stoull(argv[3]);
    } catch (...) {
        return 1;
    }

    Punto* G = new Punto(5, 1);

    if (modo == "-e" || modo == "-d") {
        procesar_archivo("input.txt", "output.txt", G, clave);
    }

    delete G;
    return 0;
}