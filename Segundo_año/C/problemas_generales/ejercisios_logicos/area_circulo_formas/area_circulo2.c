#include <stdio.h>

#define PI 3.14159
float procesar(float radio);

int main(){
    float radio, area;
    printf("Radio = ?");
    scanf("%f", &radio);
    area = procesar(radio);
    printf("area = %f", area);
}

float procesar(float r){
    float a;
    a= PI * r *r;
    return(a);
}