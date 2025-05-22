#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    srand(time(NULL));
    int numeros[]= {rand()%21+1};
    for(int i=0;i<sizeof(numeros);i++){
        printf("%d",numeros);

    }
    return 0;
}