//Creando el numero armstong recursivo
#include <stdio.h>

int armstrong(num);

int main(){
    int num = 371;
    int resultados=armstrong(num);
    printf("resultado: %d\n",resultados);
    if(resultados==num){
        printf("%d es un numero de armstrong.\n");
    }
    else{
        printf("%d no es un numero armstrong.\n");
    }
    return 0;
}
int armstrong(num){
    if(num==0){
        return 0;
    }
    else{
        int digito=num%10;
        return(digito * digito * digito) + armstrong(num / 10);
    }
}
