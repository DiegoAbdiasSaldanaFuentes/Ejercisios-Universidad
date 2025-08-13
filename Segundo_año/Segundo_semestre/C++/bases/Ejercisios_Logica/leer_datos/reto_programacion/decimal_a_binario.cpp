#include <iostream>

int main(){

    int numero_decimal= 49;
    int contador = 0;
    int binario;

    while(numero_decimal > 0){
        //si es par
        if(numero_decimal % 2==0){
            binario = 0;
            std::cout<< binario;
        }
        // si es impar
        else{
            binario = 1;
            std::cout<<binario;
        }

        //divide en dos para medir si espar o impar el numero
        numero_decimal = numero_decimal / 2;
    }
    
    return 0;
}