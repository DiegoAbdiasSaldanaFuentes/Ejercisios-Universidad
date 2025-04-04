#include<stdio.h>
/*& Ampersand o Bitwise y % Modulo*/
int main(){
    int number;
    int n;

    number = 0;
    char saludo[]="hola \n";
    printf("Hola Mundo \n");
    printf(saludo);
    printf("%i \n",number);
    for(n=0;n<=10;++n)
        printf("%2i\t%5d\t%5d\t%5d\n",n,n*n,n*n*n,n*n*n*n);


    return 0;
}
