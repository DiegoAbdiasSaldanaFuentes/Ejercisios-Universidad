/*************************************************************************
 * -Nombre autor: Diego Saldaña
 *- Nombre docente: Francisco Philip Vásquez Iglesias
 * -Nombre del proyecto: Multiplicación de matrices
 * -Problema planteado: Implementar un programa en C utilizando OpenMP 
 * que realice la multiplicacion de 2 matrices cuadradas grandes
 * -Fecha comienzo: 25-05-2025
 * -Fecha Finalización: 26-05-2025                                                   
 *                                                                                                                                         *
 *************************************************************************/

#include <omp.h>
#include <time.h>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

#define TAM 100 //advertencia no llegar a 1000

int main() {
    // Inicializar temporizadores
    LARGE_INTEGER inicio_win, fin_win, frec_win;
    QueryPerformanceFrequency(&frec_win); 
    QueryPerformanceCounter(&inicio_win);
    double inicio_omp = omp_get_wtime();
    clock_t inicio_cpu = clock();


    // Declarar matrices
    int** matris1 = (int**)malloc(TAM * sizeof(int*));
    int** matris2 = (int**)malloc(TAM * sizeof(int*));
    int** resultado = (int**)malloc(TAM * sizeof(int*));
    for (int i = 0; i < TAM; i++) {
        matris1[i] = (int*)malloc(TAM * sizeof(int));
        matris2[i] = (int*)malloc(TAM * sizeof(int));
        resultado[i] = (int*)malloc(TAM * sizeof(int));
    }

    // Llenar matrices
    int num = 0;
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            matris1[i][j] = num;
            matris2[i][j] = num;
            resultado[i][j] = 0;
            num++;
        }
    }


    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            for (int k = 0; k < TAM; k++) {
                resultado[i][j] += matris1[i][k] * matris2[k][j];
            }
        }
    }

    // Guardar resultado
    FILE* salida = fopen("resultado_multiplicacion_secuencial.txt", "w");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            fprintf(salida, "%d ", resultado[i][j]);
        }
        fprintf(salida, "\n");
    }
    fclose(salida);

    // Finalizar tiempos
    clock_t fin_cpu = clock();
    double tiempo_cpu = (double)(fin_cpu - inicio_cpu)/CLOCKS_PER_SEC;
    double fin_omp = omp_get_wtime();
    double tiempo_omp = fin_omp - inicio_omp;
    QueryPerformanceCounter(&fin_win);
    double tiempo_win = (double)(fin_win.QuadPart - inicio_win.QuadPart) / frec_win.QuadPart;

    // Mostrar tiempos
    printf("fila y columna %dx%d\n", TAM, TAM);
    printf("tiempo de CPU: %.4f segundos\n", tiempo_cpu);
    printf("tiempo real/OMP: %.4f segundos\n", tiempo_omp);
    printf("tiempo con QueryPerformanceCounter: %.4f segundos\n", tiempo_win);

    // Liberar memoria
    for (int i = 0; i < TAM; i++) {
        free(matris1[i]);
        free(matris2[i]);
        free(resultado[i]);
    }
    free(matris1);
    free(matris2);
    free(resultado);

    return 0;
}
