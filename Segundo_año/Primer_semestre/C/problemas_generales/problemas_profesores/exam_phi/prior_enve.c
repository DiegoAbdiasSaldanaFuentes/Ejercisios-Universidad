/*Implementar un programa que simule la planificación de procesos basada en prioridad con un 
mecanismo de envejecimiento para evitar la inanición de procesos de baja prioridad. Un sistema 
tiene 10 procesos que deben ejecutarse en un procesador bajo un esquema de planificación por 
prioridad. Cada proceso debe ser leído desde un archivo, el cual contiene para cada proceso: */
#include <stdio.h>

//este codigo tiene la desventaja de ver un proceso a la vez 
int main(){
    //datos
    int procesos[]={3,8,3,2,9};
    int time_llegada[]={2,3,5,1,2};
    int time_ejec[]={2,1,2,3,4};
    int prioridad[]={2,1,3,4,2};
    int i;
    //buscador de el numero menor
    int mayor=10000;
    int mayor1=10000;
    int mayor2=10000;
    int mayor3=10000;
   
    int resultado1,resultado2,resultado3,resultado4;

    //calcular el proceso menor
    for(i=0;i<5;i++){
        if(procesos[i]<mayor){
            mayor= procesos[i];
        }
    }
   
    //calcular el tiempo de llegada mas rapido
    for(i=0;i<5;i++){
        if(time_llegada[i]<mayor1){
            mayor1= time_llegada[i];
        }
    }
   

    //calcular el tiempo de ejecucion que debe durar
    for(i=0;i<5;i++){
        if(time_ejec[i]<mayor2){
            mayor2= time_ejec[i];
        }
    }
   

    //calcular la prioridad mas alta
    for(i=0;i<5;i++){
        if(prioridad[i]<mayor3){
            mayor3= prioridad[i];
        }
    }
    resultado1= mayor;
    resultado2= mayor1;
    resultado3= mayor2;
    resultado4= mayor3;
    //menor no era necesario pero se nos olvido
    printf("MENOR LLEGADA EJECUCION PRIORIDAD\n");
    printf("%d       %d         %d        %d",resultado1,resultado2,resultado3,resultado4);


    return 0;
}