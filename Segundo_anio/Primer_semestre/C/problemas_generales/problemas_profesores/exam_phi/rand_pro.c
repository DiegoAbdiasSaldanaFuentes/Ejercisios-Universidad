//Cola de ejecución con criterio: el más pequeño primero
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(){
    int i,j;
    int proc[] = {10, 5, 8, 12, 6};
    int prioridades[] = {1, 2, 1, 2, 3};
    int cant = 5; // cantidad de proceso
    srand(time(NULL));
    int procAux=10000000;
    int procPriori;
    int pos;

    for(i=0;i<cant;i++){

        //Aquí obtengo posiciones aleatorias
        pos=rand()%5;

        while(proc[pos]==-1){
            //Aquí obtengo posiciones aleatorias
            pos=rand()%5;
        }

        printf("Elemento ingresado %d\n",proc[pos]);
        proc[pos]=-1;

    }
    return 0;
}