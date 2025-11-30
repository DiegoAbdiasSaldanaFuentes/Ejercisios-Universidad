#ifndef PERSONA_H
#define PERSONA_H

#include <QString>

// Esta será tu CLASE ABSTRACTA (Item 2.7 de la rúbrica)
class Persona
{
public:
    Persona();

    // Esta línea mágica (= 0) es la que la vuelve Abstracta.
    // Significa: "Yo no sé cómo identificarme, mi hijo (Cliente) debe decirlo".
    virtual QString getIdentificacion() = 0;
};

#endif // PERSONA_H
