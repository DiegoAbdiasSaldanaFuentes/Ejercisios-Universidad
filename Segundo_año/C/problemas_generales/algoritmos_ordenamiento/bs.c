//Codigo hecho por Diego Saldaña

#include <stdio.h>
void comparar(int array[]);
void cambiar_posicion(int*n,int*b);

int main(){
    int array[]={7,4,6,9,1};
    comparar(array);
    // Mostrar array ordenado
    for (int i = 0; i < 5; i++) {
        printf("%d ", array[i]);
    }
        
    return 0;
}

void comparar(int array[]){
    /*declaramos estaticamente hasta donde llega pero debemos restar 1 para que no salga de los limites y nos arroje error
    para evitar esto podemo implementar otra funcion que  lea  la cantidad de datos que hay en el array*/
    for(int i=0;i<5 -1;i++){
        //si va a hacer asi de estatico usamos 5-1 para no pasarnos de los limites y restamos el indice i para no dar la vuelta entera
        for(int j=0;j<5-1-i;j++){
            //menor que para orden decendente y mayor que para orden ascendente
            if(array[j]>array[j+1]){
                
                cambiar_posicion(&array[j],&array[j+1]);

            }
        }
    }
}
//usamos punteros para poder modificar desde aqui el array de arriba
void cambiar_posicion(int *n, int *b){
    //declaramos una varible temporal para modificar mas a agusto los datos
    int temp= *n;
    *n=*b;
    *b=temp;
}


<<<<<<< HEAD
=======

>>>>>>> 00aeb4a48ab7dc26caede5d9156d184ec33ae310
