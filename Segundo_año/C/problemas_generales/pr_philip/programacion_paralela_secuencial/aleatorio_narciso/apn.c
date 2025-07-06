/*************************************************************************
 *  Autor: Diego Saldaña                                                 *
 *  Docente: Philip Vásquez                                              *                    
 *  Enunciado: Poder crear un programa que pueda generar 10 numeros      *
 *  aleatorio primos o narcisos                                          *
 *                                                                       *
 *  Fecha: 21-06-2025                                                    *                
 *                                                                       *                                                                      
 *************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 999
#define tamanio 100
#define generar 11

int numeros_primos();
int numeros_narcisos();

int main(){
    int resultados_numeros_primos= numeros_primos();
    int resultados_numeros_narcisos= numeros_narcisos();
    return 0;
}


int numeros_primos(){
    srand(time(NULL));
    for (int i = 1; i < generar;) {
        int numero= rand() % MAX;
        if(numero%2==1){
            printf("%d-Numeros primos: %d\n",i,numero);
            i++;

        }
    }
    printf("---------------------------------------------------------------------------------\n");
}

int numeros_narcisos(){
    int modulo= 750 % 10;
    printf("%d\n",modulo);
    for(int i = 1; i < generar;){
        int num= rand() % MAX;
        int num_verificar=num;
        int mult;
        int resultado=0;
        while(num>0){
            int num_div= num % 10;
            mult = num_div * num_div * num_div;
            resultado= resultado + mult;
            num /= 10;
        }
        if(num_verificar==resultado){
            printf("%d-Numero narciso: %d\n",i,resultado);
            i++;
        }
    }

}