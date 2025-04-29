//Cola de ejecución con criterio: el más pequeño primero
#include<stdio.h>

int main(){
    int i,j;
    int proc[] = {10, 5, 8, 12, 6};
    int prioridades[] = {1, 2, 1, 2, 3};
    int cant = 5;

    int procAux=10000000;
    int procPriori;
    int pos;

    for(j=0;j<cant;j++){
        procAux=10000000;
        for(i=0;i<cant;i++){
            if(proc[i]<procAux){
                procAux=proc[i];
                procPriori=prioridades[i];
                pos=i;
            }
        }
        proc[pos]=10000000;
        printf("El mas chico es %d con prioridad: %d\n", procAux,procPriori);
    }

    for(i=0;i<cant;i++){
        printf("%d\t",proc[i]);
    }

    return 0;
}