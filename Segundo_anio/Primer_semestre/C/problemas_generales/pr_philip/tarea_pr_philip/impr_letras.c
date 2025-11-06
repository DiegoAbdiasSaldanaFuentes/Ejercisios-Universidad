/*************************************************************************
 *  Autor: Diego Saldaña                                                 *
 *  Docente: Philip Vásquez                                              *                    
 *  Enunciado: Poder crear un programa que puede entregar el resultado   *
 *  del palabras que terminen en vocales.                                *
 *  Fecha: 19-06-2025                                                    *                
 *                                                                       *                                                                      
 *************************************************************************/
#include <stdio.h>
#include <string.h>

void buscar_vocales(char *frase);

int main() {
    char frase[] = {"La espera me agoto no se nada de vos dejaste tanto en mi en llamas me acoste y en un lento degrade supe que te perdi"};
    buscar_vocales(frase);
    return 0;
}

void buscar_vocales(char *frase) {
    char *palabras[100];

    int letras_3 = 0;
    int letras_3_5 = 0;
    int letras_5 = 0;
    int total_palabras = 0;
    int termina_en_vocal = 0;

    // separación frase usando strtok()
    char *token = strtok(frase, " ");
    while (token != NULL) {
        palabras[total_palabras] = token;
        total_palabras++;
        token = strtok(NULL, " ");
    }

    // analizar palabras
    for (int i = 0; i < total_palabras; i++) {
        char *palabra = palabras[i];
        int len = strlen(palabra);
        char ultima = palabra[len - 1];

        // verificar si termina en vocales
        if (ultima == 'a' || ultima == 'e' || ultima == 'i' || ultima == 'o' || ultima == 'u') {
            termina_en_vocal++;
        }

        // clasificar longitud
        if (len < 3) {
            letras_3++;
        } else if (len >= 3 && len <= 5) {
            letras_3_5++;
        } else {
            letras_5++;
        }
    }

    // imprimir resultados
    if (total_palabras > 0) {
        printf("Porcentaje de palabras que terminan en vocal: %.2f%%\n", (termina_en_vocal * 100.0) / total_palabras);
        printf("Palabras con menos de 3 letras: %.2f%%\n", (letras_3 * 100.0) / total_palabras);
        printf("Palabras entre 3 y 5 letras: %.2f%%\n", (letras_3_5 * 100.0) / total_palabras);
        printf("Palabras con más de 5 letras: %.2f%%\n", (letras_5 * 100.0) / total_palabras);
    } else {
        printf("No hay palabras.\n");
    }
}
