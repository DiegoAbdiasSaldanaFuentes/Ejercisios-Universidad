#include <stdio.h>
/*Se debe desarrollar un programa que simule la planificación de procesos basada en el algoritmo 
Primero el Trabajo Más Corto (SJF, Shortest Job First). El programa debe leer tres archivos de 
entrada independientes, cada uno representando una lista de procesos que deben ejecutarse en 
un procesador. */

//En caso de no dar resultado la manipulacion de archivo
int main(){
    int primer_archivo[]={3,8,3,2,9};
    int segundo_archivo[]={4,1,3,4,5};
    int tercer_archivo[]={9,5,3,8,5};
    int i; //contador
    //buscador de el numero menor
    int mayor=10000; 
    int mayor1=10000;
    int mayor2=10000;


    //primer archivo
    for(i=0;i<5;i++){
        if(primer_archivo[i]<mayor){
            mayor=primer_archivo[i];
        }
    }
   
    //segundo archivo
    for(i=0;i<5;i++){
        if(segundo_archivo[i]<mayor1){
            mayor1=segundo_archivo[i];
        }
    }
    //tercer archivo
    for(i=0;i<5;i++){
        if(tercer_archivo[i]<mayor2){
            mayor2=tercer_archivo[i];
        }
    }
    printf("Resultado del primer archivo:%d\n",mayor);
    printf("Resultado del segundo archivo:%d\n",mayor1);
    printf("Resultado del tercer archivo:%d\n",mayor2);


    

    return 0;
}
