/*************************************************************************
 *  Autor: Diego Saldaña
 *  Nombre programa:Juego de la vida                                                                   
 *  Profesor: Hugo Araya
 *  Fecha: 12/06/2025                                                              
 *  Asignatura: Estructura de Datos                                                                  
 *************************************************************************/


#include <stdio.h>

int main(){
       FILE *archivo;
    
    archivo =fopen("insectos.txt","r");
    int n[100];
    int i=0;
    while(fscanf(archivo,"%d",&n[i])==1){
        i++; 
    }




    int matris[n[0]][n[1]];
    int numero=0;
    //creacion de la matris
    for(int i=0;i<n[0];i++){
        for(int j=0;j<n[1];j++){
            matris[i][j]=numero;
        }
    }

    // agregar elementos a la matriz
    for(int i=0;i<n[0];i++){
        for(int j=0;j<n[1];j++){
            matris[n[4]][n[5]]=1;
            matris[n[6]][n[7]]=1;
            matris[n[8]][n[9]]=1;
            matris[n[10]][n[11]]=1;
            matris[n[12]][n[13]]=1;
        }
    }

    // si encuentra mas de vecinos vivos muere de lo contrario nace un nuevo insecto
    for(int i = 1; i < n[0]-1; i++){
        for(int j = 1; j < n[1]-1; j++){
            int suma = 0;
            suma += matris[i-1][j-1];
            suma += matris[i-1][j];
            suma += matris[i-1][j+1];
            suma += matris[i][j-1];
            suma += matris[i][j+1];
            suma += matris[i+1][j-1];
            suma += matris[i+1][j];
            suma += matris[i+1][j+1];
            
            //si hay mas de 2 y menos que 3 vecinos  se conserva en 0
            if(matris[i][j] == 1){
                if(suma < 2 || suma > 3){
                    matris[i][j] = 0;
                } 
                
            } else {
                // si hay mas de 3 vecinos  se transforma en 1
                if(suma == 3){
                    matris[i][j] = 1;
                }
            }
        }
    }


    //imprimir
    for(int i=0;i<n[0];i++){
        for(int j=0;j<n[1];j++){
            printf("%3d",matris[i][j]);
        }
        printf("\n");

    }
    return 0;
}
