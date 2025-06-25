#include <stdio.h>
int main(){

    int numero;
    scanf("%d", &numero);
    int secuencia[10];
    for( int i=0; numero!=0; i++ ){
        /* teoria 09/05/2025 21:46, al dividirlo entre modulo dara resultados entre 1 y 9 y el residuo dara lugar a la posicion que quedara*/
        secuencia[i] = numero % 10;
        /* teoria 09/05/2025 21:51, dividirlo entre 10 consecutivamente ira descomponiendo el numero y guardandolo*/
        numero /= 10;
    
        printf("%d ", secuencia[i]);
    }
}