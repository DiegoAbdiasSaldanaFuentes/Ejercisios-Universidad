/*Imprime los números pares entre 1
y 30
*/
#include <stdio.h>
int main(){
    int num;
    for(num = 1; num <=30;++num){
        if(num % 2 ==0){
            printf("%d\n",num);
        }
    }
    return 0;
}