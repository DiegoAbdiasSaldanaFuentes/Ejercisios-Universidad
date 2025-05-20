/*
 * Crea un programa que comprueba si los paréntesis, llaves y corchetes
 * de una expresión están equilibrados.
 * - Equilibrado significa que estos delimitadores se abren y cieran
 *   en orden y de forma correcta.
 * - Paréntesis, llaves y corchetes son igual de prioritarios.
 *   No hay uno más importante que otro.
 * - Expresión balanceada: { [ a * ( c + d ) ] - 5 }
 * - Expresión no balanceada: { a * ( c + d ) ] - 5 }
 */

//solucion de google
#include <stdio.h>

#define MAX 100 //a directiva de preprocesador que sirve para definir un nombre simbólico

int main() {
    char expresion[] = "{[a*(c+d)]-5}";
    char pila[MAX];//agrega lo simbolos abiertos como (,[,{
    int tope = -1; // pila vacía deja los simbolos que cierran como ),],}

    for (int i = 0; expresion[i] != '\0'; i++) {
        char c = expresion[i];
        if (c == '(' || c == '{' || c == '[') {
            pila[++tope] = c; // meter en la pila
        } else if (c == ')' || c == '}' || c == ']') {
            if (tope == -1) {
                printf("Expresión no balanceada\n");
                return 0;
            }

            char ultimo = pila[tope--]; // sacar de la pila

            // Verificar correspondencia
            if ((c == ')' && ultimo != '(') ||
                (c == '}' && ultimo != '{') ||
                (c == ']' && ultimo != '[')) {
                printf("Expresión no balanceada\n");
                return 0;
            }
        }
    }

    if (tope == -1) {
        printf("Expresión balanceada\n");
    } else {
        printf("Expresión no balanceada\n");
    }

    return 0;
}
