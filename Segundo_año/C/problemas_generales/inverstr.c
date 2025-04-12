/*
 * Crea un programa que invierta el orden de una cadena de texto
 * sin usar funciones propias del lenguaje que lo hagan de forma automática.
 * - Si le pasamos "Hola mundo" nos retornaría "odnum aloH"
 */

/*codigo de chatgpt*/
#include <stdio.h>

int main(){
    
    char texto[100];
    int i, longitud = 0;
    printf("Ingresa una cadena de texto: ");
    scanf("%s",&texto);
    // Calculamos la longitud manualmente
    for(i = 0; texto[i] != '\0'; i++){
        longitud++;
        printf("%s",longitud);
    }
    // Mostramos la cadena invertida
    printf("Texto invertido: ");
    for(i = longitud - 1; i >= 0; i--){
        printf("%s",longitud);
        printf("%c", texto[i]);
    }
    printf("\n");
    return 0;
    

}


