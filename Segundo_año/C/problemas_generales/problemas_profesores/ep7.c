/*Utilizar la estructura While
Visualizar en pantalla los múltiplos
de 2, comprendidos entre 0 y 40.
Incluyendo los limites.*/

#include <stdio.h>
int main(){
    int num;
    int cont=0;
    while(cont<=40){
        num = cont *2;
        printf("%d \n",num);
        cont = cont+1;
    }
    return 0;
}