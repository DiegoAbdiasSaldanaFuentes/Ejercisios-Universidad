#include <stdio.h>

int mayor(int num1,int num2){
    return(num1);
    if(num2>num1){
        return(num2);
    }
} 
int main(){
    int a,b;
    printf("ingrese dos numeros enteros:\n");
    scanf("%d %d\n",&a,&b);
    printf("El mayor es %d",mayor(a,b));
    return 0;
}