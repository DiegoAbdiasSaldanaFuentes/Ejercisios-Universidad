#include <iostream>
using namespace std;

int main(){

    int numeros= 1234, invertido=0;

    while (numeros !=0){
        int digito =numeros % 10;
        invertido = invertido * 10 + digito;
        numeros = numeros / 10;
    }
    cout<<invertido;

    return 0;
}   