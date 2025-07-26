// By Diego Saldaña
// Invirtiendo cadenas
// Fecha 10-05-2025
// 30 minutos en desarrollarse
#include <stdio.h>

int main(){
    // creamos nuestra cadena de texto
    char caracteres[]={"hola"};
    //declaramos un bucle que este decienda para que imprime de derecha a izquierda
    for(int j=3;j>=0;j--){
        //usamos 
        printf("%c",caracteres[j]);
    }
    
    return 0;
}