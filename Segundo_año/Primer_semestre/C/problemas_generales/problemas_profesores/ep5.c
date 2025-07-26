/*
Visualiza en pantalla todos los
valores comprendidos entre 10 y 15
con un incremento de 0.5 y un
contador que muestre el ordinal
correspondiente a cada numero
*/

#include <stdio.h>
int main(){
    float comnum1,comnum2;
    int contnumber;
    for(comnum1 = 10.0, comnum2 = 15.0,contnumber =1;comnum1<=comnum2;comnum1=comnum1+0.5,++contnumber){
        printf("%d\t%.1f\n",contnumber,comnum1);
    }
    return 0;
}