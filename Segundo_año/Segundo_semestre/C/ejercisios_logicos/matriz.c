#include <stdio.h>

int main() {
    int tablero[8][8] = {0};  // inicializamos la matriz en ceros
    int fila = 3;             // posición inicial (centro aproximado)
    int columna = 3;

    tablero[fila][columna] = 1; // colocamos al caballo

    printf("Posición inicial:\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%3d", tablero[i][j]);
        }
        printf("\n");
    }

    // movimiento en L: dos filas abajo y una columna a la derecha
    int dx = 2;
    int dy = 1;

    // nueva posición calculada
    int nuevaFila = fila + dx;
    int nuevaColumna = columna + dy;

    // verificamos que no se salga del tablero
    if (nuevaFila >= 0 && nuevaFila < 8 && nuevaColumna >= 0 && nuevaColumna < 8) {
        tablero[fila][columna] = 0;          // limpiamos la posición anterior
        fila = nuevaFila;                    // actualizamos fila
        columna = nuevaColumna;              // actualizamos columna
        tablero[fila][columna] = 1;          // marcamos la nueva posición
    }

    printf("\nDespués de moverse:\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%3d", tablero[i][j]);
        }
        printf("\n");
    }

    return 0;
}
