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
