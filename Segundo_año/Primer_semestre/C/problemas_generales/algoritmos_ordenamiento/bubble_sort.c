/*Algoritmo basicoy facil ideal para listas pequeñas, no grandes*/

#include <stdio.h>

// Prototipos de funciones 
void bubbleSort(int arr[], int n);
void printArray(int arr[], int size);
int calcularTamanoArray(int arr[]);

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = calcularTamanoArray(arr);  // Calculamos el tamaño manualmente desde la funcion calculartamanoarray

    printf("Array original:\n");
    printArray(arr, n);
    //le entregamo el arreglo y el resultado de la funcion calculartamanoarray
    bubbleSort(arr, n);

    printf("Array ordenado:\n");
    printArray(arr, n);

    return 0;
}

// Función para intercambiar dos elementos 
void intercambiar(int *a, int *b) {// se declara en  la misma funcione los valores a,b
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Función Bubble Sort
void bubbleSort(int arr[], int n) {
    //se declara un for para que recorra la lista
    for (int i = 0; i < n - 1; i++) {
        //se declara otro for para que recorra los indices del array
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                intercambiar(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Función para imprimir un array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Función para calcular el tamaño del array (sin sizeof)
int calcularTamanoArray(int arr[]) {
    int tamano = 0;
    while (arr[tamano] != '\0') {  // Asume que el array termina con '\0' (como strings)
        tamano++;
    }
    //retornamos tamaño hacia el main para usarse en la funcion bubblesort
    return tamano;
}