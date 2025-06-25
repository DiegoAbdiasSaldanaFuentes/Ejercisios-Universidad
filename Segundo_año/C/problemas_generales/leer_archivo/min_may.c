#include <stdio.h>

int main(){
    FILE *fpt;

    char c;
    /*abrir el archivo de datos solo para lectura*/
    if((fpt= fopen("muestra.dat","r"))==NULL)
        printf("\nERROR - no se puede abrir el archivo indicado\n");
    else /*leer y mostrar cada caracter del archivo*/
        do 
            putchar(c=getc(fpt));
        while (c != EOF);
        /*cerrar el archivo de datos*/
        fclose(fpt);
}   