// By Diego Saldaña
// Invirtiendo cadenas
// Fecha 10-05-2025

#include <stdio.h>

int main(){
    char caracteres[]={"hola"};

    for(int j=3;j>=0;j--){
        printf("%c",caracteres[j]);
    }
    
    return 0;
}