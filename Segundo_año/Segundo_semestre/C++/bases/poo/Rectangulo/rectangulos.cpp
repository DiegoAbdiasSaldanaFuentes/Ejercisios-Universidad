#include <iostream>

using namespace std;

class Rectangulo{
    private:
        float base= 5;
        float altura= 5;

    public:

        void setValor(int b, int a){
            base = b;
            altura = a;
        }

        float getBase(){
            return base;
        }

        float getAltura(){
            return altura;
        }

        float  getArea(){
            return base * altura /2;
        }



};


int main(){

    Rectangulo rectangulo1;
    rectangulo1.setValor(5,5);
    cout<<"Altura:"<<rectangulo1.getAltura()<<endl;
    cout<<"Base:"<<rectangulo1.getBase()<<endl;
    cout<<"==========Resultado=========="<<endl;
    cout<<"Resultado del Area: "<<rectangulo1.getArea()<<endl;

}