/*tecnica usada: paralelizacion con hilos (multithreading)
permire dividir el trabajo y ejecutarlo más rapido si el programador tiene multiples nucleos
Donde usar esto?: esto se usa para tareas repetitivas e independientes (como procesar datos de un arreglo
si el programa tarda mucho en ejecutarse puede beneficiarse con multiples nucleos)*/

#include <omp.h>
#include <stdio.h>
int main (){
    int num_threads = 6; // Por ejemplo, configurar 6 hilos
    omp_set_num_threads(num_threads);//Quiero usar 6 hilos cuando entre en una región paralela

    #pragma omp parallel//“A partir de aquí, ejecuta este bloque con múltiples hilos.”,  realiza el bucle  con cada hilo
    {
        int thread_id = omp_get_thread_num();//guarda el id de cada hilo  en la variable
        printf("Hola desde el hilo %d de %d hilos\n",thread_id,num_threads);
    }
    return 0;
}