#include <stdio.h>
int main(){

    int numero, mayor;
    /*para bucar el mayor se pone un numero bajo*/
    mayor= -1;
    printf("ingrese un numero:");
    scanf("%d",&numero);
    while(numero >0){
        if(numero>mayor){
            mayor=numero;
        
        }
        printf("ingrese numero:");
        scanf("%d",&numero);
    }
    printf("el mayor es: %d\n, mayor");
}