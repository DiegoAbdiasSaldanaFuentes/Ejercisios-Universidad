/*Hay 10 tipos de verduras y 10 tipos de empaques. Mostrar todas las 
posibles combinaciones. La salida debe ser de la forma: 
Verdura 1 – Empaque 1 
Verdura 1 – Empaque 2 
… 
Verdura 10 – Empaque 10  */

//codigo por Diego Saldaña
//fecha 15-05-2025
//empezo 16:02-termino 16:20

#include <stdio.h>

int main(){

    for(int i=1;i<11;i++){
        int empaque=i;
        for(int j=1;j<11;j++){
            int verdura=j;
            printf("Verdura:%d - Empaque:%d\n",verdura,empaque);
        }
    }
    return 0;
}
    //Por que funciona?
    /*R: Porque lo mas importante es el orden, aqui el primer for debe iterar empaque con el numero del contador osea empaque=1 luego 
    este debe iterar el segundo for anidado que recorrera verduras del 1 al 10, para cuando finalize este for volvera al anterior for
    para sumar empaque 2 y luego que otra vez recorra verdura del 1 al 10, el segundo for anidado seguira ejecutandose hasta que el 
    primer for acabe por eso entrega  
    Verdura 1 – Empaque 1 
    Verdura 1 – Empaque 2 
    Verdura 1 - Empaque 3 */