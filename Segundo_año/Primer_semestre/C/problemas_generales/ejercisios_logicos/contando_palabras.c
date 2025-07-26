/*
 * Crea un programa que cuente cuantas veces se repite cada palabra
 * y que muestre el recuento final de todas ellas.
 * - Los signos de puntuación no forman parte de la palabra.
 * - Una palabra es la misma aunque aparezca en mayúsculas y minúsculas.
 * - No se pueden utilizar funciones propias del lenguaje que
 *   lo resuelvan automáticamente.
 */

#include <stdio.h>
#include <string.h>

int main(){
    char palabras[100];
    int cont;
    char igual;
    char no_igual;

    printf("ingrese una palabra: ");
    scanf(" %c",&palabras);
    for(int i=0;palabras[i] != '\0' ;i++){
        cont++;
        for(i = cont - 1; i >= 0; i--){
            if(palabras[i]!=palabras[cont]){
                igual=palabras[i];
            }
            else{
                no_igual= palabras[i];
            }
        }

    }
    printf("la letra %c coincide:",igual);

    return 0;
}