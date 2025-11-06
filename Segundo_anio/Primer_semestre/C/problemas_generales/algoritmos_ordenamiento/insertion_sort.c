//codigo de IA  Blueseaks

#include <stdio.h>

void insertion_sort(int arr[]);


int main() {
    int array[] = {12, 15, 23, 8, 22, 4};
    insertion_sort(array);
    
    // Imprimir el array ordenado
    for (int i = 0; i < 6; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}

void insertion_sort(int arr[]) {
    for (int i = 1; i < 6; i++) {  // Empezamos desde el segundo elemento (i=1)
        int key = arr[i];  // Elemento a insertar
        int j = i - 1;     // Índice del último elemento de la parte ordenada
        
        // Movemos los elementos mayores que 'key' hacia la derecha
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];  // Desplazamiento (no intercambio)
            j--;
        }
        arr[j + 1] = key;  // Insertamos 'key' en su posición correcta
    }
}

