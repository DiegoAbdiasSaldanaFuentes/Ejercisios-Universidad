#include <stdio.h>

#define PI 3.14159
float procesar(float radio);

int main(){
    float radio, area;
    printf("Para parar introduzca 0");
    printf("\n Radio= ?: ");
    scanf("%f", &radio);

    while(radio){
        if(radio < 0)
            area = 0;
        else
            area = procesar(radio);
        printf("area = %f\n", area);
        printf("\n Radio= ?: ");
        scanf("%f", &radio);
    }
}

float procesar(float r){
    float a;
    a= PI * r *r;
    return(a);
}