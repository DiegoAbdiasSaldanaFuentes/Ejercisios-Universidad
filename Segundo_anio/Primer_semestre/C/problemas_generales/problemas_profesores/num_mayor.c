/*. Mostrar el valor mayor de un conjunto de números positivos ingresados por 
teclado, el ingreso de números se realiza hasta que se digite un número 
negativo. */
#include <stdio.h>
int main(){
    int array[]={4,6,2,7,3,9};
    int num_mayor=999;
    for(int i=0;i<7:i++){
        if(array[i]<num_mayor){
            num_mayor=array[i];
        }
    }
    return 0;
}


