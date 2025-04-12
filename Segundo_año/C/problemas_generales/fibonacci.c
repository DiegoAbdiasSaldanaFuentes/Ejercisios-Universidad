
/*
 * Escribe un programa que imprima los 50 primeros números de la sucesión
 * de Fibonacci empezando en 0.
 * - La serie Fibonacci se compone por una sucesión de números en
 *   la que el siguiente siempre es la suma de los dos anteriores.
 *   0, 1, 1, 2, 3, 5, 8, 13...
 */
#include<stdio.h>
int main(){
    int n,a=0,b=1,c=1;
    printf("Hasta que posición deseas ver? ");
    scanf("%d",&n);
    if(n==1){
        printf(" %d ",a);
    }
    else{
        if(n==2){
            printf(" %d \n",a);
            printf(" %d \n",b);
        }
        else{
            c=2;
            printf(" %d \n",a);
            printf(" %d \n",b);
            while(c<n){
                a+=b;
                printf(" %d \n",a);
                c++;
                if(c==n)
                    break;
                else{
                    b+=a;printf(" %d \n",b);
                    c++;
                }
        } 
    }
    
    }      
}
