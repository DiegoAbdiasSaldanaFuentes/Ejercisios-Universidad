/*Programa para calcular areas de varios circulos usando un bucle while, los resultados se alamacenan en una formacion, no se espe
cifica el numero de circulos se introduce una cadena de caractares para cada conjunto de datos*/
#include <stdio.h>

#define PI 3.14159
float procesar(float radio);

int main(){
    int n,i=0;
    struct{
        char texto[20];
        float radio;
        float area;
    }circulo[10];

    printf("Para parar introduzca FIN en el identificador");
    printf("\n Identificador: ");
    scanf("%s", &circulo[i].texto);
    while(circulo[i].texto[0] !='F' || circulo[i].texto[1] != 'I' ||circulo[i].texto[2] != 'N'){
        printf("Radio = ? ");
        scanf("%f", &circulo[i].radio);

        if(circulo[i].radio < 0)
            circulo[i].area = 0;
        else
            circulo[i].area = procesar(circulo[i].radio);
        ++i;
        printf("\n Identificador: ");
        scanf("%s", circulo[i].texto);
    }
    n=--i; /*el mayor valo de i*/

    /*presentar los elementos de la formacion*/
    printf("\nRelacion de los resultados\n\n");
    for(i=0;i<=n;++i){
        printf("%s    Radio = %f       Area= %f\n", circulo[i].texto,circulo[i].radio, circulo[i].area );
    }
}

float procesar(float r){
    float a;
    a= PI * r *r;
    return(a);
}