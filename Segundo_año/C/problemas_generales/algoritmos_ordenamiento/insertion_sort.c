<<<<<<< HEAD
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

=======
/*Insertion sort: Dividir el array en una parte ordenada y la otra desordenada, toma elementoos
de la parte desrdenada y los inserta en la posicion correcta dentr de la parte oordenada*/

//Codigo Por Dego

#include <stdio.h>
void  insertion_sort(array);
int main(){
    int array[]={12,15,23,8,22,4};
    insertion_sort(array);
    return ;
}

void insertion_sort(arr){
    int num_orden;
    int num_desor;
    for(int i=0;i<6+1-1;i++){
        if(arr[i]<arr[i+1]){
            num_orden=arr[i];

        }
        else if(arr[i]>arr[i+1]){
            num_desor=arr[i];
        }
    }
    printf("%d\n",num_orden);
    printf("%d\n",num_desor);

}
>>>>>>> 00aeb4a48ab7dc26caede5d9156d184ec33ae310
