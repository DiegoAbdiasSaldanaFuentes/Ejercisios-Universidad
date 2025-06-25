/*EJERCISIO DOS DE SUMATORIA*/
/*MALO*/

#include <stdio.h>
#include <math.h>

int main(){
    int n,i;
    float suma=0;
    printf("ingrese el valor de N:");
    scanf(" %d",&n);
    printf("ingrese el valor de i:");
    scanf(" %d",&i);
    for(i;i<=n;i++){
        suma = suma + (pow(2,i+1)-pow(2, i))/(i+1);
        printf("%.2f\n",suma);
    }
    return 0;
}