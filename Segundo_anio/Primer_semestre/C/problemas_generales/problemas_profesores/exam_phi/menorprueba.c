#include <stdio.h>

int main(){
    //creamo un array de 5 proceos
    int procesos[]={6,2,5,4,5};
    /*como bucamos el menor asumimos que no hay ningun numero mayor
    a ese osea al primer intento sera verdad y ese numero sera comparado con el siguiente*/ 
    int guardarmenor=10000;
    /*creamos nuetro contador*/
    int j;
    for(j=0;j<5;j++){
        /*usamos el contador para iterar proceso por proceso y se compara primero por el 10000
        y ese numero pr ejemplo el 1, sera comparado por el siguiente osea el 2 y asi*/
        if(procesos[j]<guardarmenor){
            /*guarda el menor en la variable "guardarmenor"*/
            guardarmenor=procesos[j];
        }
    }
    printf("%d",guardarmenor);
    return 0;
}