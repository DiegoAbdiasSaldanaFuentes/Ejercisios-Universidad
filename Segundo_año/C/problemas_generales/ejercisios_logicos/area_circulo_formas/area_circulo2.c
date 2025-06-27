#include <stdio.h>

/*int main(){
    float radio,area;
    printf("Radio = ?");
    scanf("%f", &radio);
    area= 3.14159 * radio *radio;
    printf("area= %f",area);
    return 0;
}
    */

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