#include <stdio.h>

// === Prototipos de funciones ===
int buscar_mejor_proceso(int *tiempos_llegada, int *prioridades, int *estados, int tiempo_actual, int n);
int ejecutar_proceso(int *tiempos_restantes, int *estados, int proceso, int *procesos_terminados);
int aplicar_envejecimiento(int *prioridades, int *estados, int n);
void mostrar_estado(int proceso, int tiempo_actual);

// === Función principal ===
int main() {
    // Datos de los procesos
    int procesos[] = {1,2,3,4,5};
    int tiempos_llegada[] = {2,3,5,1,2};
    int tiempos_ejecucion[] = {2,1,2,3,4};
    int prioridades[] = {2,1,3,4,2};
    int estados[] = {0,0,0,0,0}; // 0 = no ejecutado, 1 = ejecutado

    int i;
    int n = 5; // Número de procesos
    int tiempo_actual = 0;
    int procesos_terminados = 0;

    // Bucle principal: continúa hasta que todos los procesos terminen
    while(procesos_terminados < n) {
        int mejor_proceso = buscar_mejor_proceso(tiempos_llegada, prioridades, estados, tiempo_actual, n);

        if(mejor_proceso != -1) {
            ejecutar_proceso(tiempos_ejecucion, estados, mejor_proceso, &procesos_terminados);
            mostrar_estado(procesos[mejor_proceso], tiempo_actual);
        } else {
            printf("Tiempo %d: CPU inactiva\n", tiempo_actual);
        }

        aplicar_envejecimiento(prioridades, estados, n);
        tiempo_actual++;
    }

    printf("Todos los procesos han sido ejecutados.\n");
    return 0;
}

// === Funciones ===

// Buscar el proceso con mejor prioridad disponible para ejecutarse
int buscar_mejor_proceso(int *tiempos_llegada, int *prioridades, int *estados, int tiempo_actual, int n) {
    int mejor_proceso = -1;
    int mejor_prioridad = 6; // Mayor a la prioridad máxima (que es 5)

    for(int i = 0; i < n; i++) {
        if(tiempos_llegada[i] <= tiempo_actual && estados[i] == 0) { // Llegó y no ha sido ejecutado
            if(prioridades[i] < mejor_prioridad) {
                mejor_prioridad = prioridades[i];
                mejor_proceso = i;
            }
        }
    }
    return mejor_proceso;
}

// Ejecutar el proceso encontrado
int ejecutar_proceso(int *tiempos_restantes, int *estados, int proceso, int *procesos_terminados) {
    tiempos_restantes[proceso]--; // Ejecuta 1 unidad de tiempo

    if(tiempos_restantes[proceso] == 0) {
        estados[proceso] = 1; // Marcar como terminado
        (*procesos_terminados)++; // Incrementar cantidad de terminados
    }
    return 0;
}

// Aumentar la prioridad (bajar el número) de procesos que llevan esperando
int aplicar_envejecimiento(int *prioridades, int *estados, int n) {
    for(int i = 0; i < n; i++) {
        if(estados[i] == 0 && prioridades[i] > 1) {
            prioridades[i]--; // Aumenta la prioridad (máximo hasta 1)
        }
    }
    return 0;
}

// Mostrar el estado del sistema en cada iteración
void mostrar_estado(int proceso, int tiempo_actual) {
    printf("Tiempo %d: Ejecutando proceso PID %d\n", tiempo_actual, proceso);
}
