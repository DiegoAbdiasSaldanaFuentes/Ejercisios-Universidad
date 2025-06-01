/*
 * Crea un programa que cuente cuantas veces se repite cada palabra
 * y que muestre el recuento final de todas ellas.
 * - Los signos de puntuación no forman parte de la palabra.
 * - Una palabra es la misma aunque aparezca en mayúsculas y minúsculas.
 * - No se pueden utilizar funciones propias del lenguaje que
 *   lo resuelvan automáticamente.
 */

#include <stdio.h>

int main(){

    char palabra[100];
    char  charepit[1];
    int i,longitud=0;
    printf("ingrese una caden de texto:\n");
    scanf(" %s",&palabra);
    printf("ingrese el caracter que quiere buscar?:");
    scanf(" %c",&charepit);
    // se calculaa la longitud de la palabra
    for(i = 0; palabra[i] != '\0'; i++){
        longitud++;
    }
    // mostrar
    for(i = longitud + 1; i >= 0; i--){
        printf("%s",longitud);
        printf("%c", palabra[i]);
    }
    printf("%d",longitud);
    return 0;
}