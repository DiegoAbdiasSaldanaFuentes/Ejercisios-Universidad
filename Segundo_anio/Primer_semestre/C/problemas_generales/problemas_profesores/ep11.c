/*EJERCIIO NUMERO DOS DE SUMATORIA*/
/*MALO*/

#include <stdio.h>
#include <math.h>

int main(){
    int n,i,j,k;
    printf("ingrese el valor de N:");
    scanf(" %d",&n);
    for(i=1;i<=n;i++){
        j=pow(-1,i+1);
        k=(j)*(i/pow(2,i));
        printf("%d\t",j);
    }
    return 0;
}