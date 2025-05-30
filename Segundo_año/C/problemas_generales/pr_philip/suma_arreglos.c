/*************************************************************************
 * -Nombre autor: Diego Saldaña
 *- Nombre docente: Francisco Philip Vásquez Iglesias
 * -Nombre del proyecto: Suma de elementos de un arreglo
 * -Problema planteado: Implementar un programa en C utilizando OpenMP 
 * que realice la suma de todos los elementos de un arreglo
 * -Fecha comienzo: 25-05-2025
 * -Fecha Finalización: 26-05-2025                                                   
 *                                                                                                                                         
 *************************************************************************/
#include <omp.h>
#include <time.h>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

#define TAM 100000000

int main(){
    LARGE_INTEGER inicio_win, fin_win, frec_win;
    QueryPerformanceFrequency(&frec_win);
    QueryPerformanceCounter(&inicio_win);

    clock_t inicio_cpu = clock();
    double inicio_omp = omp_get_wtime();

    int* arr = (int*)malloc(TAM * sizeof(int));
    double* resultado_guardado = (double*)malloc(TAM * sizeof(double));
    int* num_array1 = (int*)malloc(TAM * sizeof(int));

    // Inicializar arreglo
    for(int k = 0; k < TAM; k++){
        num_array1[k] = k;
    }

    // Calcular resultados secuencialmente
    for(int i = 0; i < TAM; i++){
        resultado_guardado[i] = i + num_array1[i];
    }

    // Guardar resultados
    FILE *salida = fopen("resultados_secuencial.txt", "w");
    for (int j = 0; j < TAM; j++) {
        fprintf(salida, "%d\n", (int)resultado_guardado[j]);
    }   
    fclose(salida);

    clock_t fin_cpu = clock();
    double tiempo_cpu = (double)(fin_cpu - inicio_cpu)/CLOCKS_PER_SEC;  
    double fin_omp = omp_get_wtime();
    double tiempo_omp = fin_omp - inicio_omp;
    QueryPerformanceCounter(&fin_win);
    double tiempo_win = (double)(fin_win.QuadPart - inicio_win.QuadPart) / frec_win.QuadPart;

    printf("Ejecutando version secuencial de la suma de arreglos\n");
    printf("Cantidad de datos a calcular:%d\n",TAM);
    printf("Tiempo de CPU: %.4f segundos\n", tiempo_cpu);
    printf("Tiempo real/OMP, usando un solo nucleo: %.4f segundos\n", tiempo_omp);
    printf("Tiempo medido con QueryPerformanceCounter: %.4f segundos\n", tiempo_win);

    free(arr);
    free(resultado_guardado);
    free(num_array1);

    return 0;
}
