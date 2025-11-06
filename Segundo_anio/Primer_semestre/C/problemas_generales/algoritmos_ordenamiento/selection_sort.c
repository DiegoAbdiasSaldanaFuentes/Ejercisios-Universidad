/*selecciona el elemento más pequeño o grande, la estrategia es divide el array en dos partes
pasos: 1.encontrar el minimo 2.intercambiar con el primer elemento 3.expandir el elemento 4.repetir*/

//creado por Diego Saldaña
#include <stdio.h>
//defino mis funciones
int tamano_array(int array[]); //credo para calcurar el tamaño del array y asi ser usado en los bucles
void selection_sort(int array[],int arr_tam);//funcion principal donde ordenara el array
void intercambiar(int*n,int*b);// intercambiamos los datos
int minimo(int n[],int b);//buscara el minimo

int main(){
    int array[]={26,66,12,43,22,0};
    int arr_tam= tamano_array(array);
    int num_min =minimo(array,arr_tam);
    selection_sort(array,arr_tam);

    printf("Tamano del array: ");
    printf("%d\n",arr_tam);
    printf("Minimo:");
    printf("%d\n",num_min);
    //imprimir el array ordenado
    for (int i = 0; i < 5; i++) {
        printf("Arry ordenado:");
        printf("%d\n", array[i]);
    }
        
    return 0;

}


int minimo(int n[],int b){
    int num_buscar=9999;
    for(int i=0;i<b;i++){
        if(n[i] < num_buscar){
            num_buscar=n[i];
        }
    }
    return num_buscar;

}

int tamano_array(int arr[]){
    int tamano=0;
    while(arr[tamano] != '\0'){
        tamano++;
    }
    return tamano;
    
}

void selection_sort(int array[], int arr_tam){
    for(int i=0;i <arr_tam;i++){
        int index_min=i;
        //para no pasarnos de los limites y restamos el indice i para no dar la vuelta entera
        for(int j  = i + 1 ; j < arr_tam ;j++){
            if(array[j]<array[index_min]){
                index_min=j;
            }
        }
        intercambiar(&array[i],&array[index_min]);
    }
}

void intercambiar(int*n,int*b){
    int temp= *n;
    *n=*b;
    *b=temp;
}