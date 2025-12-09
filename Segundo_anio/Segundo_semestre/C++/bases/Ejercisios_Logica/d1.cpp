/*
Resumen del ConceptoEste ejercicio se centra en operaciones aritméticas básicas y el uso del bucle while para descomponer y 
manipular un número entero. Es fundamental para entender cómo trabajar con los dígitos individuales de un número 
sin convertirlo a una cadena de texto (string).TareaEscribe un programa en C++ que pida al usuario un número entero positivo
y calcule la suma de todos sus 
dígitos.Ejemplo del ConceptoSi el usuario ingresa el número 1234:Sumaríamos $1 + 2 + 3 + 4$.El resultado esperado es 10. */
#include <iostream>

int main(){

    int numero;
    std::cout<<"Ingrese un numero: ";
    std::cin>>numero;

    int i = 4;

    while(numero>0){

        int nt= numero %10;
        int tn = numero /10;
        std::cout<<nt<<std::endl;

        std::cout<<tn<<std::endl;
        numero--;

    }
    return 0;
}