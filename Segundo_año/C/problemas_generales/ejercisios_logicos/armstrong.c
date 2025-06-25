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
    int num_verificar=num;
    int mult;
    int resultado=0;
    while(num>0){
        int num_div= num % 10;
        mult = num_div * num_div * num_div;
        resultado= resultado + mult;
        num /= 10;
    }
    printf("resultado: %d\n",resultado);
    printf("numero a verificar: %d\n",num_verificar);
    if(num_verificar==resultado){
        printf("tu numero es narciso");
    }else{
        printf("tu numero no es narciso");
    }


return 0;
}