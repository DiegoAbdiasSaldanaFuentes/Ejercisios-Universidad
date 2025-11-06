#include <stdio.h> 
struct pareja{ 
    int a,b; 
}; 


void f1(struct pareja *); 
int main(){ 
    struct pareja p = { 13, 17}   
    /* inicialización de los miembros*/ 
    f1(&p); 
    printf("valor de a:%d valor de b:%d\n",p.a,p.b);  
    /* escribe 14 y 18 */ 
    return 0; 
} 
void f1(struct pareja *q){ 
    q->a++;   
    /* equivalente a (*q.a)++ pero más usado */ 
    q->b++; 
    return; 
} 