#include <stdio.h>
int main(){
    int n=6;
        if(n %2==0){
            n= n/2;
            printf("%d\t",n);
        }
        if(n%2==1){
            n= n*3+1;
            printf("%d\t",n);
        }
        
    return 0;
}