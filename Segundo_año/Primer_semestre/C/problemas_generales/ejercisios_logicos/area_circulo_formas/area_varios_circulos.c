#include <stdio.h>

#define PI 3.14159
float procesar(float radio);

int main(){
    float radio, area;
    int cont, n;
    printf("N de circulos?: ");
    scanf("%d", &n);

    for(cont = 1 ;cont <=n;++cont){
        printf("\n circulo n %d: Radio= ?",cont);
        scanf("%f", &radio);
        if(radio < 0)
            area = 0;
        else
            area = procesar(radio);
        printf("area = %f\n", area);
    }
}

float procesar(float r){
    float a;
    a= PI * r *r;
    return(a);
}