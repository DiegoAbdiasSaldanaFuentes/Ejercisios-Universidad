#include <iostream>
#include <string>

using namespace std;

class Banco{
    private:

    string titular;
    float saldo= 0;

    public:

    void setAtributos(string name, float sal){
        titular = name;
        saldo = sal;
    }

    string getTitular(){
        return titular;
    }

    float getSaldo(){
        return saldo;
    }

    void depositar(float depo){
        saldo += depo;
    }

    void retirar(float reti){

        if(saldo-reti <0){
            cout<<"saldo insuficiente"<<endl;
        }else{
            saldo -= reti;
        }

    }

};

int main(){

    Banco cuenta_papa;
    cuenta_papa.setAtributos("Luis",1000);
    cout<<cuenta_papa.getTitular()<<endl;
    cout<<"El saldo de Luis es :"<<cuenta_papa.getSaldo()<<endl;
    cuenta_papa.depositar(1000);
    cout<<"se realizo un deposito de 1000, saldo total:"<<cuenta_papa.getSaldo()<<endl;
    cuenta_papa.retirar(1100);
    cout<<"se hizo un retiro de 1500 el saldo total es de: "<<cuenta_papa.getSaldo()<<endl;


    Banco cuenta_mama;
    cuenta_mama.setAtributos("Camila",100);
    cout<<"El saldo de Camila es:"<<cuenta_mama.getSaldo()<<endl;

}