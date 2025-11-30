#ifndef PERSONA_H
#define PERSONA_H

#include <QString>


class Persona
{
public:
    Persona();


    // Se define la clase abstracta
    virtual QString getIdentificacion() = 0;
};

#endif // PERSONA_H
