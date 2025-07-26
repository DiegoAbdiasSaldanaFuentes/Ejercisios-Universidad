#include <stdio.h>
/*
int main(){
    int x = 10;
    printf("%d\n",x);
    printf("%d\n",&x);
    int* punt= &x;
    
    printf("%u",punt);
    return 0;
}
*/

/*
int jugar(int* n){
    int y = *n;
    y = (y +2)/2 +2 -(3 *y);
    *n = y;

}

int  main(){
    int x = 10;
    jugar(&x);
    printf("%d\n",x);
    return 0;
}
*/

/*
int main(){
    int* punt =NULL, var =14;
    punt = &var;
    printf("%#x,%#x",punt,&var);// la salida de la misma: direccion
    printf("\n%d,%d",*punt,var);
    return 0;
}
*/


int main(){
    int a,b,c,*p1,*p2;
    p1 = &a;
    *p1 = 1;
    p2 = &b;
    *p2 = 2;
    p1 = p2;
    *p1 = 0;
    p2 = &c;
    *p2 = 3;
    printf("%d %d %d\n", a, b, c);

    return 0;
}


