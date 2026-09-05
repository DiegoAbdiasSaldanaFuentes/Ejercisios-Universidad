#include <iostream>
#include <vector>
#include <fstream>
#include <omp.h>
#include <cstdint>

using namespace std;

long long modExp(long long base, long long exp, long long mod) {
    long long res = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        exp = exp >> 1; 
        base = (base * base) % mod;
    }
    return res;
}

int main(int argc, char* argv[]) {
    if (argc < 4) return 1;

    string modo = argv[1];
    int num_threads = 1;
    long long exponente = 17; // Clave fallback
    long long n = 3233;       // n fijo (p=61, q=53) por seguridad de bloque
    
    try {
        num_threads = stoi(argv[2]);
        exponente = stoull(argv[3]);
    } catch (...) {
        return 1;
    }

    omp_set_num_threads(num_threads);

    ifstream inFile("input.txt", ios::binary | ios::ate);
    if (!inFile) return 1;
    streamsize size = inFile.tellg();
    inFile.seekg(0, ios::beg);

    ofstream outFile("output.txt", ios::binary);
    if (!outFile) return 1;

    if (modo == "-e") {
        // Encriptar: 1 byte a 8 bytes (long long)
        vector<uint8_t> in_buffer(size);
        inFile.read((char*)in_buffer.data(), size);
        vector<long long> out_buffer(size);

        #pragma omp parallel for
        for (long long i = 0; i < size; i++) {
            out_buffer[i] = modExp((long long)in_buffer[i], exponente, n);
        }
        outFile.write((char*)out_buffer.data(), size * sizeof(long long));
        
    } else {
        // Desencriptar: 8 bytes (long long) a 1 byte
        long long num_blocks = size / sizeof(long long);
        vector<long long> in_buffer(num_blocks);
        inFile.read((char*)in_buffer.data(), size);
        vector<uint8_t> out_buffer(num_blocks);

        #pragma omp parallel for
        for (long long i = 0; i < num_blocks; i++) {
            out_buffer[i] = (uint8_t)modExp(in_buffer[i], exponente, n);
        }
        outFile.write((char*)out_buffer.data(), num_blocks);
    }

    inFile.close();
    outFile.close();
    return 0;
}