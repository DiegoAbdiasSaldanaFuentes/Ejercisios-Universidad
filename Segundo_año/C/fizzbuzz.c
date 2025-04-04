#include <stdio.h>
int main(){
    int i = 100;
    int number;
    for(number=1;number<=100;++number){
        if(number % 3 == 0 && number % 5 ==0){
            printf("fizzbuzz\n");
        }
        else if(number % 3 == 0){
            //number ="fizz";
            printf("fizz \n");
        }
        else if(number % 5 ==0){
            printf("buzz \n");
        }
        else{
            printf("%d \n",number);
        }
        //printf("%d\n",);
    }
    return 0;
}