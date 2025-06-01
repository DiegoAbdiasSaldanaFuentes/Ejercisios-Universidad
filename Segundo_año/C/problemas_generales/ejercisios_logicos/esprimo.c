#include <stdio.h>
int main(){
    int esprim;
    printf("ingrese un numero:");
    scanf("%d",&esprim);
    if(esprim % 2 ==1){
        printf("el %12d es un numero primo",esprim);
    }
    else{
        printf("no es un numero primo");
    }
    return 0;
}