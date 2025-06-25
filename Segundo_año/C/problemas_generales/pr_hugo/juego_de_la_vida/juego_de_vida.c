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
    
    archivo = fopen("insectos.txt", "r");
    int n[100];
    int i = 0;
    while(fscanf(archivo, "%d", &n[i]) == 1){
        i++; 
    }

    int matris[n[0]][n[1]];
    int nueva[n[0]][n[1]];
    int numero = 0;

    // llenar la matriz de ceros
    for(int i = 0; i < n[0]; i++){
        for(int j = 0; j < n[1]; j++){
            matris[i][j] = numero;
        }
    }

    // colocar insectos en sus posiciones
    for(int i = 0; i < n[3]; i++){
        int fila = n[4 + (i * 2)];
        int columna = n[5 + (i * 2)];
        matris[fila][columna] = 1;
    }

    // aplicar ciclos evolutivos
    for(int ciclo = 0; ciclo < n[2]; ciclo++){

        for(int i = 0; i < n[0]; i++){
            for(int j = 0; j < n[1]; j++){
                int suma = 0;

                // revisar los 8 vecinos 
                for(int dx = -1; dx <= 1; dx++){
                    for(int dy = -1; dy <= 1; dy++){
                        if(dx != 0 || dy != 0){ 
                            int ni = i + dx;
                            int nj = j + dy;
                            if(ni >= 0 && ni < n[0] && nj >= 0 && nj < n[1]){
                                suma += matris[ni][nj];
                            }
                        }
                    }
                }

                // reglas de vida y muerte
                if(matris[i][j] == 1){
                    if(suma == 2 || suma == 3){
                        nueva[i][j] = 1;
                    } else {
                        nueva[i][j] = 0;
                    }
                } else {
                    if(suma == 3){
                        nueva[i][j] = 1;
                    } else {
                        nueva[i][j] = 0;
                    }
                }
            }
        }

        // copiar nueva a matris
        for(int i = 0; i < n[0]; i++){
            for(int j = 0; j < n[1]; j++){
                matris[i][j] = nueva[i][j];
            }
        }
    }

    // imprimir resultado final
    for(int i = 0; i < n[0]; i++){
        for(int j = 0; j < n[1]; j++){
            printf("%3d", matris[i][j]);
        }
        printf("\n");
    }

    return 0;
}
