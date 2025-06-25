#include <stdio.h>

int main(){

    int numero;
    do{

        printf("ingrese un numero:\n");
        scanf("%d",&numero);
        if((numero%2)==0){
            printf("el numero:%d es par\n",numero);

        }
        else{
            printf("el numero:%d es impar",numero);
        }
    }
    while(numero!=0);
    return 0;
}