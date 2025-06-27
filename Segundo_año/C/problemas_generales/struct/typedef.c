#include <stdio.h> 
//los struct son para poder ingresar un pronorme a  nuestro struct facilitando la forma en la que nosotros lo llamamos
typedef struct{
    int dia;
    int mes;
    int anio;
} fecha;

int main(){
    fecha a={1,2,3};
    printf("Dia:%d Fecha:%d Anio:%d",a.dia,a.mes,a.anio);
    return 0;
}