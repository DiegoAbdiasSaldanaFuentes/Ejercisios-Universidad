/*************************************************************************
 *   Nombre: Diego Saldaña                                               *
 *   Proyecto: Algoritmo que tome datos de un texto para ordenarlos y    *
 *   entregar el resultado en otro archivon de texto                     *
 *   Metodo de ordenamiento: Bubble Sort                                 *
 *   Fecha: 18/05/2025                                                   *
 *   Complejidad: Cuadratica                                             *
 *                                                                       *
 *                                                                       *
 *                                                                       *
 *                                                                       *
 *                                                                       *
 *                                                                       *
 *                                                                       *
 *************************************************************************/



#include <stdio.h>
void bubble_sort(int num[],int n);

int main(){
    FILE *archivo;
    
    archivo =fopen("numeros.txt","r");
    int numeros[100];
    int i=0;
    while(fscanf(archivo,"%d",&numeros[i])==1){
        i++; 
        //contador para salirse del bucle ya que  leera todo lo que haya en numeros.txt una vez
    }
    bubble_sort(numeros,i);
    for(int j=0; j<i;j++){//mostrar lo que esta contenido en el archivo guardado en la variable numeros
        printf("%d\t",numeros[j]);
    }
    //guardar la salida en un archivo txt
    FILE *salida;
    salida=fopen("resultado.txt","w");
    for(int n=0; n<i;n++){
    fprintf(salida,"%d\t",numeros[n]);
    }
    


    fclose(archivo);
    return 0;
}

void bubble_sort(int num[],int n){
    for(int l=0;l<n;l++){
        for(int k=0; k<n-1;k++){
            if(num[k]>num[k+1]){
                // Intercambiar
                int temp = num[k]; //la variable temporal almanecara temporalmente arr[j]
                num[k] = num[k+1]; //el primer valor arr[j]  toma el valor de arr[j+1] ose si arr[j] era 5 y arr[j+1] 4 entonces arr[j] valdra 4
                num[k+1] = temp; // y como restante quedara arr[j+1] con 5, y asi ordenandose
            }
        }

        }
    
}