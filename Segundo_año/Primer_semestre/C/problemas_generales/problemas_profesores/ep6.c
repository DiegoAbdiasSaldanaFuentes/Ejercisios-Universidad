/*Obtener una tabla del código ASCII
*/
#include <stdio.h>
int main(){
    int x;
    char c;
    for (x=32; x<=255; x++){
    c=x;
    printf("%d...%c\t",x,c);
    }
    return 0;
}