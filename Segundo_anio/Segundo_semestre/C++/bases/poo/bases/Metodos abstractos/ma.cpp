//Usando destructor virtual
#include <iostream>
using namespace std;

class Figura{
public:
    virtual ~Figura(){cout <<"Destructor de Figura\n";}
};

class Circulo : public Figura{
public:
    ~Circulo() {cout << "Destructor de Ciruclo\n";}
};

int main(){
    Figura * f = new Circulo();
    delete f;
}