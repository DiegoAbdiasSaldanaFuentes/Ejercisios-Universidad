/*
 * Escribe un programa que muestre por consola (con un print) los
 * números de 1 a 100 (ambos incluidos y con un salto de línea entre
 * cada impresión), sustituyendo los siguientes:
 * - Múltiplos de 3 por la palabra "fizz".
 * - Múltiplos de 5 por la palabra "buzz".
 * - Múltiplos de 3 y de 5 a la vez por la palabra "fizzbuzz".
 */


#include <stdio.h>
int main(){
    int i = 100;
    int number;
    for(number=1;number<=100;++number){
        if(number % 3 == 0 && number % 5 ==0){
            printf("fizzbuzz\n");
        }
        else if(number % 3 == 0){
            //number ="fizz";
            printf("fizz \n");
        }
        else if(number % 5 ==0){
            printf("buzz \n");
        }
        else{
            printf("%d \n",number);
        }
        //printf("%d\n",);
    }
    return 0;
}