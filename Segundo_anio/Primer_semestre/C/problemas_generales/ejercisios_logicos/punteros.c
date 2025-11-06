#include <stdio.h>
int main(){
    int *punt=NULL,var=14;
    punt=&var;
    printf("%#x",punt,&var);/*la misma direccion*/
    printf("\n%d,%d",*punt,var);/*salida 14,14.*/
    return 0;
}
