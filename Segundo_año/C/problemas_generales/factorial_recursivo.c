/********************************************
 * Codigo: Factorial recursivo
 * Hecho: ChatGPT
 ********************************************/
#include <stdio.h>

// Función recursiva
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1; // Caso base
    } else {
        return n * factorial(n - 1); // Paso recursivo
        
    }
}

int main() {
    int numero = 5;
    int resultado = factorial(numero);
    printf("El factorial de %d es %d\n", numero, resultado);
    return 0;
}
