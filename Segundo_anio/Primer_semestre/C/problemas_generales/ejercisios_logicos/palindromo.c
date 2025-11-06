//verificar si un numero es palindromo osea que se lea del derecho al revez
// Por Diego Saldaña
//12/05/2025
//どんなコードも完璧ではない。

#include <stdio.h>
int main(){
    int num_a=12321;
    int reverso=0;
    int original=num_a;
    while(num_a >0){
        int digito = num_a % 10;
        reverso= reverso*10+ digito;
        num_a= num_a /10;
    }
    if(original== reverso){
        printf("Tu numero es un palindromo");
    }
    else{
        printf("tu numero no es un palindromo");
    }
    return 0;
}