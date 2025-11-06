#include <stdio.h>
#include <string.h>


struct Persona{

    char nombre[50];
    int edad;
    float altura;
};
int main(){
    struct Persona p1;
    strcpy(p1.nombre, "Diego");
    p1.edad =19;
    p1.altura =1.69;
    printf("Nombre: %s\n",p1.nombre);
    printf("Edad: %d\n",p1.edad);
    printf("Altura: %.2f\n",p1.altura);
    return 0;
}