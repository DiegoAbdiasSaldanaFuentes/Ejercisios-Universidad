#include <stdio.h>

int main() {
    // Datos iniciales
    /*Guarda el PID, identificador unico*/
    int procesos[] = {3, 8, 3, 2, 9};
    /*El tiempo que llega cada proceso al sistema*/
    int time_llegada[] = {2, 3, 5, 1, 2};
    /*El tiempo que necesita ejecutarse*/
    int time_ejec[] = {2, 1, 2, 3, 4};
    /*la prioridad cual es la más urgente*/
    int prioridad[] = {2, 1, 3, 4, 2};

    /*tiempo actual*/
    int tiempo = 0;
    /*procesos terminados*/
    int procesos_terminados = 0;
    /*numero de procesos*/
    int cant = 5;

    printf("Simulacion de ejecucion:\n\n");
    /*El while sera el corazon del programa, si no quedan procesos este acabara*/
    while (procesos_terminados < cant) {
        // ningun elegido aún
        int mejor_proceso = -1;
        int mejor_prioridad = 6; // Recuerda: prioridad menor es mejor (1 es mejor que 5)

        // Buscar el mejor proceso disponible
        for (int i = 0; i < cant; i++) {
            /*al principio tomara todo como TRUE, ya que toma procesos que ya llegaron 
            y no han terminado, de los disponibles elige el que posea menor prioridad numerica
            osea el más urgente de momento*/
            if (time_llegada[i] <= tiempo && ejecutado[i] == 0) {
                //prioridad es mejor (más pequeña) que la del mejor proceso encontrado hasta ahora?
                if (prioridad[i] < mejor_prioridad) {
                    mejor_prioridad = prioridad[i];
                    mejor_proceso = i;
                }
            }
        }
        /*encontrara el mejor proceso para ejecutar*/
        if (mejor_proceso != -1) {
            // Ejecutar 1 unidad de tiempo
            printf("Tiempo %d: Ejecutando Proceso PID %d (Prioridad %d, Tiempo restante %d\n", 
                   tiempo, procesos[mejor_proceso], prioridad[mejor_proceso], time_ejec[mejor_proceso]);
            /*Le restamos 1 a su tiempo de ejecución porque lo estamos ejecutando 1 unidad de tiempo.*/
            time_ejec[mejor_proceso]--;

            // Si terminó de ejecutarse
            /*¿Terminó el proceso? (ya no le queda tiempo).*/
            if (time_ejec[mejor_proceso] == 0) {
                ejecutado[mejor_proceso] = 1;
                /*Si terminó, aumentamos el contador terminado.*/
                procesos_terminados++;
                printf("    --> Proceso PID %d Terminado\n", procesos[mejor_proceso]);
            }
        } else {
            /*Si no había ningún proceso para ejecutar, imprimimos que la CPU está ociosa.*/
            printf("Tiempo %d: CPU ocioso (no hay procesos listos)\n", tiempo);
        }

        // Envejecimiento: subir prioridad (si todavía no están ejecutados)
        for (int i = 0; i < cant; i++) {
            if (time_llegada[i] <= tiempo && ejecutado[i] == 0 && i != mejor_proceso) {
                if (prioridad[i] > 1) { // No subir de prioridad 1 (1 ya es la mejor)
                    prioridad[i]--;
                    printf("    >> Proceso PID %d aumenta su prioridad a %d\n", procesos[i], prioridad[i]);
                }
            }
        }

        tiempo++;
    }

    printf("\nTodos los procesos fueron ejecutados.\n");

    return 0;
}
