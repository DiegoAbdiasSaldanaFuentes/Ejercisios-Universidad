/**
 * Arreglo para practicar matrizes y vectores en un futuro
 * 07/09/2025
 */

#include <iostream>
using namespace std;

int main(){

    int filas = 3, columnas = 4;
    int matriz[3][4]; //arreglo 3x4

    //iniciarlizar manualmente
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            matriz[i][j] = i + j; //solo para probar
        }
    }

    //imprimir
    for(int i = 0; i < filas; i++){
        for (int j = 0; j <columnas; j++){
            cout << matriz[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}