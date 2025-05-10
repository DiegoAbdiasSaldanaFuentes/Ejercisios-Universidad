//By Diego Saldaña
// Decimal a Binario
// Tiempo: 20 minutos
#include <stdio.h>
int main(){
    int numero_decimal=156;
    int contador=0;
    int binario;
    while(numero_decimal>0){
        //Si es par
        if(numero_decimal % 2==0){
            binario= 0;
            printf("%d",binario);
        }
        //Si es impar
        else{
            binario=1;
            printf("%d",binario);

        }
        //Divide en dos para medir si es par o impar el numero
        numero_decimal= numero_decimal /2;

    }
    return 0;
}
//notas: una variable que puede desecharse es el binario ya que imprimiendo unicamente un 0 o 1 ya cumpliria