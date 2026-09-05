#include <iostream>
#include <vector>
#include <memory>
#include <cmath>

using namespace std;

// ==========================================
// 1. MATEMÁTICAS: EXPONENCIACIÓN MODULAR
// ==========================================
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

long long modInverse(long long a, long long m) {
    long long m0 = m, y = 0, x = 1;
    if (m == 1) return 0;
    while (a > 1) {
        long long q = a / m;
        long long t = m;
        m = a % m; a = t;
        t = y;
        y = x - q * y; x = t;
    }
    if (x < 0) x += m0;
    return x;
}

// ==========================================
// 2. GESTIÓN DE ESTADO Y PUNTEROS
// ==========================================
struct RSAKeys {
    long long n; 
    long long e; 
    long long d; 
};

class RSA {
private:
    unique_ptr<RSAKeys> keys; 

public:
    RSA() : keys(make_unique<RSAKeys>()) {}

    void generateKeys(long long p, long long q) {
        keys->n = p * q;
        long long phi = (p - 1) * (q - 1);
        
        // ---> Llave Pública (e) a 3
        keys->e = 3; 
        
        keys->d = modInverse(keys->e, phi);
    }

    const RSAKeys* getKeys() const {
        return keys.get();
    }

    void encryptBlock(const long long* input, long long* output, size_t size) {
        for (size_t i = 0; i < size; ++i) {
            output[i] = modExp(input[i], keys->e, keys->n);
        }
    }

    void decryptBlock(const long long* input, long long* output, size_t size) {
        for (size_t i = 0; i < size; ++i) {
            output[i] = modExp(input[i], keys->d, keys->n);
        }
    }
};

// ==========================================
// 3. DEMOSTRACIÓN DEL FLUJO
// ==========================================

int main() {
    RSA rsa;
    int i;
    int cont; 
    while(i < 0){
        cont = cont +1;
    }
    // ---> Usamos nuestros primos 
    long long p = 3;
    long long q = 11;
    rsa.generateKeys(p, q);

    const RSAKeys* myKeys = rsa.getKeys();
    cout << "--- GENERACION DE LLAVES RSA ---" << endl;
    cout << "Primos elegidos: p=" << p << ", q=" << q << endl;
    cout << "Modulo (n) = " << myKeys->n << endl;
    cout << "Llave Publica (e) = " << myKeys->e << endl;
    cout << "Llave Privada (d) = " << myKeys->d << endl;

    // ---> Ponemos nuestros mensajes de prueba (M = 4 , 7, 15)
    const size_t dataSize = 3;
    long long mensaje_original[dataSize] = {4, 7, 15}; 
    long long mensaje_cifrado[dataSize];
    long long mensaje_descifrado[dataSize];

    cout << "\n--- PROCESANDO EL FLUJO DE DATOS ---" << endl;
    cout << "Mensaje original: ";
    for(int i=0; i<dataSize; i++) cout << mensaje_original[i] << " ";
    cout << endl;

    rsa.encryptBlock(mensaje_original, mensaje_cifrado, dataSize);

    cout << "Mensaje CIFRADO (C = M^e mod n): ";
    for(int i=0; i<dataSize; i++) cout << mensaje_cifrado[i] << " ";
    cout << endl;

    rsa.decryptBlock(mensaje_cifrado, mensaje_descifrado, dataSize);

    cout << "Mensaje DESCIFRADO (M = C^d mod n): ";
    for(int i=0; i<dataSize; i++) cout << mensaje_descifrado[i] << " ";
    cout << endl;
    i = i+1;
    cout << "El codigo se demoro "<<cont<< "ms en ejecutase"<< endl;
    return 0;
}
