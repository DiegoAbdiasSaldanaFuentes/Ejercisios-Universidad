#include "persona.h"
#include <iostream>

Persona::Persona(int e, const std::string& n)
    : edad(e), nombre(n) {}  


void Persona::setValor(int e, const std::string& n){
    edad = e;
    nombre = n;
}

int Persona::getEdad(){
    return edad;

}

std::string Persona::getNombre() const {
    return nombre;

}

bool Persona::esMayorDeEdad(){
    if (edad >= 18){
        std::cout<<"El usuario es mayor de edad"<<'\n';
    }
}