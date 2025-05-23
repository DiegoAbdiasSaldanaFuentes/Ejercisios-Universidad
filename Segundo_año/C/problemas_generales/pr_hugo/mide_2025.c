#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#define MAXIMO 200000

void lee_datos(int array[], int N);
void muestra_datos(int array[], int N);
void burbuja(int array[], int N);
void insercion(int array[], int N);
void shellsort(int array[], int N);
void swap(int* a, int* b);
int particion (int arr[], int bajo, int alto);
void quickSort(int arr[], int bajo, int alto);

int main(){
    clock_t t_1, t_2;   
    double tiempo; 
    int i, N, cont;
    int array[MAXIMO];
    int numero;

    lee_datos(array, MAXIMO); 

    for (cont = 10000; cont < MAXIMO; cont = cont + 10000){
        // Bloque a medir el tiempo  
        t_1 = clock(); 

        //burbuja(array, cont);
        //insercion(array, cont);
        //shellsort(array, cont);
        //quickSort(array, 0, cont-1);

        t_2 = clock(); 

        tiempo = (double)(t_2 - t_1) / CLOCKS_PER_SEC;
        printf("Para %d elementos demoro %.6f segundos\n", cont, tiempo); 
    }
    return 0;
}

void burbuja(int array[], int N){
    int i, j, aux;
    for(i=0;i<N-1;i++){   
        for(j=0;j<N-i-1;j++){ 
            if(array[j+1]<array[j]){       
                aux=array[j+1];       
                array[j+1]=array[j];  
                array[j]=aux;
            }   
        } 
    } 
}

void insercion(int matrix[], int N) {
    int i, temp, j;
    for (i = 1; i < N; i++) {
        temp = matrix[i];
        j = i - 1;
        while ( (matrix[j] > temp) && (j >= 0) ) {
            matrix[j + 1] = matrix[j];
            j--;
        }
        matrix[j + 1] = temp;
    }
}

void shellsort(int array[], int N){
    int salto, cambios, i, aux;
    for(salto = N/2; salto!=0; salto = salto/2){
        cambios = 1;
        while (cambios != 0){
            cambios=0; 
            for(i = salto;i < N; i++){
                if(array[i-salto]>array[i]){ 
                    aux=array[i];
                    array[i]=array[i-salto]; 
                    array[i-salto]=aux; 
                    cambios++;
                } 
            }
        }
    }
}

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}
 
int particion (int arr[], int bajo, int alto){
    int pivote, i, j;
    pivote = arr[alto];
    i = (bajo - 1);
    for (j = bajo; j <= alto- 1; j++){
        if (arr[j] <= pivote){
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[alto]);
    return (i + 1);
}
 
void quickSort(int arr[], int bajo, int alto){
	int pi;
    if (bajo < alto){
        pi = particion(arr, bajo, alto);
        quickSort(arr, bajo, pi - 1);
        quickSort(arr, pi + 1, alto);
    }
}

void lee_datos(int array[], int N){
    FILE *ent;
    int i, numero;
    ent = fopen("aleatorio.txt", "r");
    for (i = 0; i < N; i++){
        fscanf(ent,"%d",&numero);
        array[i] = numero;
    }
    fclose(ent);
}

void muestra_datos(int array[], int N){
    int i;
    printf("\n ------------------ \n");
    for (i = 0; i < N; i++){
        printf("%d\n",array[i]);
    }
}
