#include "Numeros.h"
#include <stdexcept> // para lanzar excepciones en Division
#include <cmath>     // para esPrimo opcionalmente

// ====== Construcción y acceso ======
Numeros_naturales::Numeros_naturales(int v) : Valor(v) {}

void Numeros_naturales::setValor(int v) {
    Valor = v;
}

int Numeros_naturales::getValor() const {
    return Valor;
}

// ====== Operaciones (modifican el estado) ======
void Numeros_naturales::Suma(int su) {
    Valor += su;
}

void Numeros_naturales::Resta(int re) {
    Valor -= re;
}

void Numeros_naturales::Multiplicacion(int mul) {
    Valor *= mul;
}

void Numeros_naturales::Division(int div) {
    if (div == 0) {
        throw std::runtime_error("Division por cero");
    }
    Valor /= div; // división entera
}

// ====== "Resultados" (solo devuelven el estado actual) ======
int Numeros_naturales::Suma() const {
    return Valor;
}

int Numeros_naturales::Resta() const {
    return Valor;
}

int Numeros_naturales::Multiplicacion() const {
    return Valor;
}

int Numeros_naturales::Division() const {
    return Valor;
}

// ====== Preguntas ======
bool Numeros_naturales::esPar() const {
    return (Valor % 2) == 0;
}

bool Numeros_naturales::esPrimo() const {
    if (Valor < 2) return false;
    if (Valor % 2 == 0) return Valor == 2;
    for (int i = 3; i * i <= Valor; i += 2) {
        if (Valor % i == 0) return false;
    }
    return true;
}

// ====== Collatz de Valor ======
std::vector<int> Numeros_naturales::Collatz() const {
    std::vector<int> seq;
    if (Valor <= 0) return seq; // Collatz se define para naturales positivos

    long long n = Valor; // usar ancho mayor por seguridad
    seq.push_back(static_cast<int>(n));

    while (n != 1) {
        if (n % 2 == 0) n /= 2;
        else           n = 3*n + 1;

        // si te preocupa overflow, aquí podrías validar límites
        seq.push_back(static_cast<int>(n));
    }
    return seq;
}
