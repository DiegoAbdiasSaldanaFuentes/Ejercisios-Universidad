#include <iostream>
using namespace std;

class Rectangulo{
public:
    int base;
    float altura;

    Rectangulo(){
        base = 0;
        altura = 0.0;
    }

    Rectangulo(int bas){
        base= bas;
        altura= 0.0;
    }

    Rectangulo(int bas, float alt){
        base = bas;
        altura = alt;
    }

    float Area(){
        return base * altura;
    }

};

int main(){
    Rectangulo r1;
    Rectangulo r2(2);
    Rectangulo r3(2,4.0);

    cout<<r1.Area()<<endl;
    cout<<r2.Area()<<endl;
    cout<<r3.Area()<<endl;
}