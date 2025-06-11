/********************************************
 * Codigo: Factorial recursivo
 * Hecho: formula de internet
 ********************************************/
#include <stdio.h>
int i=0;
// Función recursiva
int factorial(int n) {
    i++;
    printf("%d\n",i);
    if (n == 0 || n == 1) {
        return 1; // Caso base
    } else {
        return n * factorial(n - 1); // Paso recursivo
        
    }
}

int main() {
    int numero = -1;
    int resultado = factorial(numero);
    printf("El factorial de %d es %d\n", numero, resultado);
    return 0;
}
