#include <stdio.h>

float promleng(float num1){
    if(num1>=4.0){
        printf("Lenguaje:aprobao\n");
    }
    else{
        printf("Lenguaje:reprobao\n");
    }
    return num1;
}
float promath(float num2){
    if(num2>=4.0){
        printf("Matematicas:aprobao\n");
    }
    else{
        printf("Matematicas:reprobao\n");
    }
    return num2;
}
float promcien(float num3){
    if(num3>=4.0){
        printf("Ciencias:aprobao\n");
    }
    else{
        printf("Ciencias:reprobao\n");
    }
    return num3;
}

int main(){
    float a,b,c;
    printf("ingrea tus promedios:");
    scanf("%f %f %f", &a, &b, &c);
    printf("-----------------------\n");
    printf("%.2f\n",promleng(a));
    printf("%.2f\n",promath(b));
    printf("%.2f\n",promcien(c));
    return 0;
}