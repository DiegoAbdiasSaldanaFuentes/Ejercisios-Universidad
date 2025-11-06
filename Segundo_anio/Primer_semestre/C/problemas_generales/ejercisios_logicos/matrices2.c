#include <stdio.h>

int main(){

    int num[3][4]={0,1,2,3,4,5,6,7,8,9,10,11};
    /*si pongo otro numero que no sea el correcto habra desbordamiento de memoria*/
    printf("--------------MATRIS DE NUMEROS-------------\n");
    for(int i=0;i<3;i++){// 3 filas 
        for(int j=0;j<4;j++){ // 4 columnas
            printf("%3d",num[i][j]);
        }
        printf("\n");
    }
    /*es muy sensible usar cadenas de texto ya que al final cuentan con un '\0' que indica el final de str*/
    /*para mayor optimizacion se puede declarar la primera parte de la matriz en blanco [][5]*/
    printf("--------------MATRIS DE TEXTO--------------\n");
    char str[][5]={"hola","hola","hola","hola","hola"};
    for(int i=0;i<5;i++){// 5 filas 
        for(int j=0;str[i][j] != '\0';j++){ // solo asta '\0'
            printf("%c",str[i][j]);
        }
        printf("\n");
    }



    return 0;
}