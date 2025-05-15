/*Hay 10 tipos de verduras y 10 tipos de empaques. Mostrar todas las 
posibles combinaciones. La salida debe ser de la forma: 
Verdura 1 – Empaque 1 
Verdura 1 – Empaque 2 
… 
Verdura 10 – Empaque 10  */

//codigo por Diego Saldaña
//fecha 15-05-2025
//empezo 16:02-termino 

#include <stdio.h>

int main(){
    //Por que funciona?
    //R: Porque 
    for(int i=1;i<11;i++){
        int empaque=i;
        printf("´´empaque test:%d\n",empaque);

        for(int j=1;j<11;j++){
            int verdura=j;
            printf("verdura test:%d\n",verdura);

            printf("Verdura:%d - Empaque:%d\n",verdura,empaque);
        }
    }
    return 0;
}