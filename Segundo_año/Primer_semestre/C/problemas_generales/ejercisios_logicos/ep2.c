/*Suma los números comprendidos
entre 100 y 200
*/
#include <stdio.h>
int main(){
    int numcom1, numcom2;
    int cont;
    int sum;
    for(numcom1=100,numcom2=200;numcom1<=numcom2;++numcom1){
        sum = numcom1 + numcom2;
        printf("%d \n",sum);
    }
    return 0;

}
