#ifndef NUMEROS_H
#define NUMEROS_H

#include <vector>

class Numeros_naturales {
private:
    int Valor;

public:
    // Construcción y acceso básico
    explicit Numeros_naturales(int v = 0);
    void setValor(int v);
    int  getValor() const;

    // Operaciones que MODIFICAN el estado (tu "void que trabaja")
    void Suma(int su);
    void Resta(int re);
    void Multiplicacion(int mul);
    void Division(int div); // división entera por ahora

    // "Resultados" (tu "int que retorna"), aquí SOLO devuelven el estado actual
    int Suma() const;             // devuelve Valor
    int Resta() const;            // devuelve Valor
    int Multiplicacion() const;   // devuelve Valor
    int Division() const;         // devuelve Valor

    // Preguntas (no modifican estado)
    bool esPar() const;
    bool esPrimo() const;

    // Collatz sobre el estado actual
    std::vector<int> Collatz() const;
};

#endif
