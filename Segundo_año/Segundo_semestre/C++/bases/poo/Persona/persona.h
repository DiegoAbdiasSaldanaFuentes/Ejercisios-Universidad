#ifndef PERSONA_H
#define PERSONA_H

#include <string>

class Persona{
private:

    int edad;
    std::string nombre;

public:
    // Constructor y acceso
    explicit Persona(int edad, const std::string& nombre);
    void setValor(int e, const std::string& n);
    std::string getNombre() const;
    int getEdad() const;

    void mostrarEdad();
    bool esMayorDeEdad();
};



#endif