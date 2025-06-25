#include <stdio.h>

int main() {
    int filas = 4;    // Número de filas de la matriz
    int columnas = 5; // Número de columnas

    // Matriz con insectos vivos (1) o vacíos (0)
    int matriz[4][5] = {
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 0, 0, 1}
    };

    // Cambios en filas para vecinos (arriba, abajo)
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    // Cambios en columnas para vecinos (izquierda, derecha)
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    // Recorremos toda la matriz
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {

            int vecinosVivos = 0; // Contador de insectos vecinos vivos

            // Revisamos los 7 vecinos
            for (int k = 0; k < 8; k++) {
                int filaVecino = i + dx[k];
                int colVecino = j + dy[k];

                // Verificamos que el vecino esté dentro de la matriz
                if (filaVecino >= 0 && filaVecino < filas && colVecino >= 0 && colVecino < columnas) {
                    if (matriz[filaVecino][colVecino] == 1) {
                        vecinosVivos++; // Si vecino tiene insecto, sumamos 1
                    }
                }
            }

            // Mostramos cuántos vecinos vivos tiene esta celda
            printf("Celda (%d,%d) tiene %d vecinos vivos\n", i, j, vecinosVivos);
        }
    }

    return 0;
}
