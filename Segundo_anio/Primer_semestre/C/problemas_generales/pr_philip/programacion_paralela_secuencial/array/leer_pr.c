#include <stdio.h>

int main(){
    int numeros[5] ={12,5,2,87};
    for (int i=0;i<5;i++){
        scanf("%d\n", &numeros[i]);
    }
    for (int i=0;i<5;i++){
        printf("%d\n",numeros[i]);
    }
    return 0;
}