/*************************************************************************
 *Programa: BlackJack o Veintiuno                                                                       
 *Nombre: Diego Saldaña                                                                      
 *Fecha: 22-05-2025                                                                       
 *                                                                       *
 *                                                                       *
 *                                                                       *
 *                                                                       *
 *                                                                       *
 *                                                                       *
 *                                                                       *
 *                                                                       *
 *                                                                       *
 *************************************************************************/


#include <stdio.h>
#include <stdlib.h>  //random
#include <time.h>   //tiempo

int main(){
    srand(time(NULL)); //iniciamos la semilla con la hora actual
    int numeros = rand() %21 + 1;
    int jugador1= numero1;
    printf("%d\n",numero1);
    int jugador2=numero2; 
    printf("%d\n",numero2);
    int crupier = numero3;
    printf("%d\n",numero3);

    if(jugador1>21){
        printf("jugador1 pierde");
        if(jugador2 > crupier  && jugador2<=21){
            printf("jugador2 gana");
        }
        else{
            printf("jugador2 pierde gana crupier");
        }
    }
    else if(jugador2 >21){
        printf("jugador2 pierde");
        if(jugador1 > crupier  && jugador1<=21){
            printf("jugador1 gana");
        }
        else{
            printf("jugador1 pierde gana crupier");
        }
    }
    else{
        if(jugador1>jugador2){

            if(jugador1 > crupier  && jugador1<=21){
                printf("jugador1 gana");
            }
            else{
                printf("jugador1 pierde gana crupier");
            }
        }
        else if(jugador1==jugador2){
            printf("empate");
        }
        else{
                    if(jugador2 > crupier  && jugador2<=21){
                        printf("jugador2 gana");
                    }
                    else{
                        printf("jugador2 pierde gana crupier");
                    }
        }
    }
    return 0;
}