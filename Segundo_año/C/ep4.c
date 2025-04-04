/*Calcular el promedio de notas de n
alumnos
*/
/*Problemas con scanf con enter, Agregar un espacio en blanco antes del & y tambien antes del %*/
#include <stdio.h>
#include <string.h>
int main(){
    float notalum1,notalum2,notalum3;
    printf("ingrese su nota en Matematicas: \n");
    scanf(" %f", &notalum1);
    printf("ingrese su nota en Ciencias: \n");
    scanf(" %f", &notalum2);
    printf("ingrese su nota en Lengua: \n");
    scanf(" %f", &notalum3);
    if(notalum1+notalum2+notalum3 / 3 >=5.0){
        printf("aprobao");
    }
    else{
        printf("reprobao");
    }
    return 0;
}