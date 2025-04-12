/* Ejercisio 1
Visualiza los números del 1 al 10
Imprimir los números del 1 al 10 en
forma ascendente
*/ 

#include <stdio.h>
int main(){
    int num;
    printf("De forma ascendente: \n");
    for(num = 1;num <=10;++num){
        printf("%d \n",num);
    }
    printf("de forma decendente: \n");
    for(num =10;num >=1;--num){
        printf("%d \n",num);
    }
}