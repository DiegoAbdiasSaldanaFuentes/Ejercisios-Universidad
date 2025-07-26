#include <stdio.h>
#include <ctype.h>

int main(){
    char letras[80];
    int count, aux;

    /*Leer la linea*/

    for(count=0; (letras[count]=getchar()) != '\n';++count);
    aux=count;

    for(count=0; count < aux;++count)
        putchar(toupper(letras[count]));
    return 0;
}