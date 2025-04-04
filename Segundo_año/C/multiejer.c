#include <stdio.h>
int main(){
    int usernum;
    int usernumlimit;
    int useresult;
    int n;
    int numusermulti;
    printf("ingrese un numero para su tabla de multiplicar: \n");
    scanf("%i",&usernum);
    printf("ingrese el limite de su tabla: \n");
    scanf("%i",&usernumlimit);
    for(n=1;n<=usernumlimit;++n){
        numusermulti = usernum * n;
        printf("%d x %d = %d\n",n,usernumlimit,numusermulti);
    
    }
    return 0;

}
