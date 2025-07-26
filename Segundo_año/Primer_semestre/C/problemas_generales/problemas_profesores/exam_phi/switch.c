#include <stdio.h>

int main(){
    char letra;
    printf("ingrese una letra:");
    scanf("%c",&letra);
    switch(letra){
        case 'a':
        case 'A':
            printf("se ingreso una vocal igual a 'a'o 'A' = %c",letra);
            break;
        case 'e':
        case 'E':
            printf("se ingreso una vocal igual a 'e'o 'E' = %c",letra);
            break;
        case 'i':
        case 'I':
            printf("se ingreso una vocal igual a 'i'o 'I' = %c",letra);
                break;
        case 'o':
        case 'O':
            printf("se ingreso una vocal igual a 'e'o 'E' = %c",letra);
            break;
        case 'u':
        case 'U':
            printf("se ingreso una vocal igual a 'u'o 'U' = %c",letra);
            break;
    }
    return 0;
}