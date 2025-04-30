#include <stdio.h>

/*la matrices son array multidimensionales, esto permite más que un array lineal*/
int main(){
    /*creamos una matriz 5x5 osea cinco columnas cinco filas*/
    int matriz[5][5];
    /*creamos el numero con el que comenzara nuestra matriz*/
    int numeros=1;
    /*creamo un  primer bucle para rellenar la columna*/
    for(int i=0;i<5;i++){
        /*creamos un segundo bucle para rellenar la fila*/
        for(int j=0;j<5;j++){
            /*agregamos nuetros datos*/
            matriz[i][j] = numeros++;
        }
        
    }
    /*realizamos la mismaa funcion de arriba pero solo para imprimir*/
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            /*imprimimos y dejamos tres espacios para que sea más legible*/
            printf("%3d",matriz[i][j]);
        }
        // salto de linea
        printf("\n");

    }
    
    
    return 0;
}