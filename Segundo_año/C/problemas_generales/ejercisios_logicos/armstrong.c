/*************************************************************************
 *  Nombre del algoritmo: Numero Armstrong
 *  Descripcion del algoritmo: identificar si un numero es armstrong, que este al ser separado y elevarlo por la cantidad
 *  del tamaño del numero
 *  Autor: Diego Saldaña
 *  Fecha: 31-05-2025                                                                                                                                         
 *************************************************************************/
#include <stdio.h>

int main(){
    int num=371;
    int mult;
    int resultado=0;
    while(num>0){
        int num_div= num % 10;
        mult = num_div * num_div * num_div;
        resultado= resultado + mult;
        num /= 10;
    }

    printf("%d",resultado);

return 0;
}