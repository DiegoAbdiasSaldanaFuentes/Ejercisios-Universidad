#include <stdio.h>

int main(){
    int n;
    int sum=0;
    printf("ingrese un numero:");
    scanf("%d",&n);

    while(n>0){
        sum = sum + n;
        n =n-1;
    }
    printf("el resultado de la sumatoria es %d",sum);
    return 0;
}