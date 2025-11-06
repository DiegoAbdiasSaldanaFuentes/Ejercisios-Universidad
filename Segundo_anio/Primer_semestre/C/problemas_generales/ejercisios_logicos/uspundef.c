#include <stdio.h>
#include <string.h>

int multiplicar(int*n){
    int y= *n;
    y= y * 1;
    *n=y;
    printf("%d",*n);
}









float divicion(int*n){
    if(*n !=0){
        int y= *n;
        y= y / 2;
        *n=y;
        printf("%d",*n);
    }
    else{
        printf("no puedes dividir entre 0");
    }
    }


int restar(int*n){
    int y= *n;
    y= y -1;
    *n=y;
    printf("%d",*n);
}

int sumar(int*n){
    int y= *n;
    y= y +1;
    *n=y;
    printf("%d",*n);
}

int main(){
    char operador;
    int numero;
    printf("ingrese el operador que desea trabajar: \n");
    scanf(" %c",&operador);
    printf("ingrese unnumero: \n");
    scanf(" %d", &numero);


    if(operador=='+'){
        sumar(&numero);
    }
    
    else if(operador=='-'){
        restar(&numero);
    }
    else if(operador=='/'){
        divicion(&numero);
    }
    else if(operador=='x'){
        multiplicar(&numero);
    }
    else{
        printf("operador no encontrado");
    }
    
    return 0;
}