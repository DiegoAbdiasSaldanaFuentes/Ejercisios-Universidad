#include <stdio.h>
//creacion de una piramide de ateriscos en c

int main(){
    int n,j;
    for(n=1;n<=10;n++){
        for(j=10;j>n;j--){
            printf("*");
        }
    printf("\n");
    }
    return 0;
}