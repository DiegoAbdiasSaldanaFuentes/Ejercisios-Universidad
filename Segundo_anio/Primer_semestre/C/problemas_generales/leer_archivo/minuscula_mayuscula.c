#include <stdio.h>
#include <ctype.h>

int main(){
    FILE *fpt;
    char c;

    /*Abrir un archivo nuevo solo para escritura*/
    fpt= fopen("muestra.dat","w");
    /*leer cada caracter y escribir su mayuscula correspondiente en el archivo*/
    do
        putc(toupper(c=getchar()),fpt);
        while(c!='\n');
        /*cerrar el archivo de datos*/
        fclose(fpt);
}