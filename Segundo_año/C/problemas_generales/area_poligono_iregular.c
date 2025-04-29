
/*debe entrar los datos del poligono regular y salir el reultado del area
la formula seria multiplicar lado del poligono por todos sus lados teniendo el perimetro
luego multiplicar su perimetro por su apotema (ap), que es la media del lado despues mutiplicar perimetro por apotema
y tendriamos area dividiendola por dos*/
#include <stdio.h>
float resolucion(float*lados, float*lados_total,float*apotema,float*resultado);

int main(){
    float lado=8.0;
    float lados_total=7;
    float apotema=6.93;
    float resultado;
    resolucion(&lado,&lados_total,&apotema,&resultado);
    printf("El Area del poligono iregular es:%.2f",resultado);
    return 0;
}

float resolucion(float*lados, float*lados_total,float*apotema,float*resultado){
    float Perimetro=(*lados) * (*lados_total);
    float Area = (Perimetro * (*apotema))/2;
    *resultado=Area;

}
