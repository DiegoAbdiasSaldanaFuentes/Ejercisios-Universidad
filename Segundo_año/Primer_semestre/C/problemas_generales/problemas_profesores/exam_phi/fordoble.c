#include <stdio.h>

int main(){
    int i,j;
    for(i=0,j=50;i<10 & j!=10;i++,j=j-10){
        printf("i:%d y j=%d\n",i,j);
    }
    return 0;
}