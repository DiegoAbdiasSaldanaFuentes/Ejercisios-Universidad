#include <iostream>

using namespace std;

class Numeros{
    private:
    
        int Valor= 5;

    public:

        //seter y getter
        void setValor(int num){
            Valor=num;
        }

        int getValor(){
            return Valor;
        }

        //Metodos
        int Suma(int n){
            return Valor += n;
        }



};

int main(){
    Numeros numeros1;
    numeros1.setValor(50);
    numeros1.Suma(5);
    cout<<numeros1.getValor();

    return 0;
}