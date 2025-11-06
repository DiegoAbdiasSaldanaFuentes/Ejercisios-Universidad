/*
* Autor: Diego Saldaña
* Fecha: 01-08-2025
* Ejercisio: Escribe un programa que muestre por consola (con un print) los
* números de 1 a 100 (ambos incluidos y con un salto de línea entre
* cada impresión), sustituyendo los siguientes:
* - Múltiplos de 3 por la palabra "fizz".
* - Múltiplos de 5 por la palabra "buzz".
* - Múltiplos de 3 y de 5 a la vez por la palabra "fizzbuzz".
*
*/

#include <iostream> //biblioteca estandar de entrada y salida

int main(){

    for(int i=0; i<100;i++){
        if(i % 3==0 && i % 5==0){
            std::cout <<"FizzBuzz"<< std::endl;
        }else if(i % 5 ==0){
            std::cout <<"Fizz"<< std:: endl;
        }else if(i % 3 ==0){
            std::cout <<"Buzz"<< std::endl;
        }else{
            std::cout << i << std::endl;
        }

    }

    return 0;
}