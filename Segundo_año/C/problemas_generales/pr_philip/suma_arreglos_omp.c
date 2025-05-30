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


#include <omp.h>//paralelismo
#include <time.h>// lo usamos para medir el tiempo de la cpu
#include <stdio.h> //libreria de entrada y salida
#include <windows.h> //usamos la libreria windows para poder usar el contador de alta precision queryperformancefrequiency
#include <stdlib.h> //uso para malloc y free
#define TAM 100000000



int main (){
    //usamos  QueryPerformanceCounter de alta precision para tener la mejor precision posible
    LARGE_INTEGER inicio_win, fin_win, frec_win;
    QueryPerformanceFrequency(&frec_win); // obtiene la frecuencia del contador
    QueryPerformanceCounter(&inicio_win);

    //inicio de tiempos
    double inicio_omp = omp_get_wtime(); 
    clock_t inicio_cpu = clock();

    //datos y resultados, usando malloc que nos permite jugar con grandes cantidades de memoria 
    int* arr = (int*)malloc(TAM * sizeof(int));
    double* resultado_guardado = (double*)malloc(TAM * sizeof(double));
    int* num_array1 = (int*)malloc(TAM * sizeof(int));

    //iniciar arreglo
    for (int i = 0; i < TAM; i++) {
        num_array1[i] = i;
    }
    int num_threads = 20; // Por ejemplo, configurar 20 hilos
    omp_set_num_threads(num_threads);//Quiero usar 20 hilos cuando entre en una región paralela

    #pragma omp parallel for//“A partir de aquí, ejecuta este bloque con múltiples hilos.”,  realiza el bucle  con cada hilo
    for(int j = 0; j < TAM; j++){
        resultado_guardado[j] = j + num_array1[j]; 
    }

    //guardar resultado
    FILE *salida = fopen("resultados_omp.txt", "w");
    for (int j = 0; j < TAM; j++) {
        fprintf(salida, "%d\n", (int)resultado_guardado[j]); 
    }   
    fclose(salida);

    //Fin del tiempo CPU
    printf("Ejecutando version usando multiples hilos de la computadora\n");
    printf("Cantidad de datos a calcular:%d\n",TAM);

    clock_t fin_cpu = clock();
    double tiempo_cpu = (double)(fin_cpu - inicio_cpu)/CLOCKS_PER_SEC;  
    printf("Tiempo de CPU: %.4f segundos\n", tiempo_cpu);

    double fin_omp = omp_get_wtime();
    double tiempo_omp = fin_omp - inicio_omp;
    printf("Tiempo real/OMP, usando %d nucleos: %.4f segundos\n",num_threads, tiempo_omp);

    //Usamos el QueryPerformanceCounter para medir el tiempo
    QueryPerformanceCounter(&fin_win);
    double tiempo_win = (double)(fin_win.QuadPart - inicio_win.QuadPart) / frec_win.QuadPart;
    printf("Tiempo medido con QueryPerformanceCounter: %.4f segundos\n", tiempo_win);

    // Libera la  memoria usada para evitar un exceso
    free(arr);
    free(resultado_guardado);
    free(num_array1);

    return 0;
}
