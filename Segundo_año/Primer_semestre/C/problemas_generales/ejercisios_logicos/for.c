#include <stdio.h>
int main(){
    int i,j;/*creamos dos variables*/
    for(i=1;i<=10;++i){
        for(j=10;j<=i;--j){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}