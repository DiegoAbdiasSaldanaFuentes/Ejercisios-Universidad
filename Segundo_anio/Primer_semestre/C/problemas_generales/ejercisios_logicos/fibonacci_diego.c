// Codigo Sucesion de Fibonacci
// Por Diego Saldaña
// 10-05-2025
// tiempo: 50 minutos en desarrollarse
// Nivel dificil
#include <stdio.h>
int main(){
    //definimos estaticamente las variables num1 y num2 estas seran ya estan definidas 
    int num1=0;
    int num2=1;
    //creamos el primer contador para el for
    int contador=0;
    //segundo "contador" para el if
    int vueltas=50;
    for(int i=0;i<=vueltas;i++){
        num1+=num2;
        printf("%d ",num1);
        //usamos un if para "pausar" la suma y que no entrege 1 y 2 como resultado
        if(contador<vueltas){
            // tomamos el resultado del anterior lo sumamos y guardamos en la misma variable num2 para que sea usada arriba
            num2+=num1;
            printf("%d ",num2);
        }
    }

    return 0;
}