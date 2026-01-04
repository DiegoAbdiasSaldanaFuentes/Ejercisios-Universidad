#include <iostream>
#include <string>


struct Canciones{
    std::string titulo;

    Canciones*siguiente;

};

int main(){

    Canciones* c1= new Canciones;
    c1->titulo="Another Five Night s";
    c1->siguiente=nullptr;

    Canciones* c2= new Canciones;
    c2->titulo="Five night s freddy";
    c2->siguiente=nullptr;


    c1->siguiente =c2;
    
    std::cout<<"Reproduciendo: "<<c1->titulo<<std::endl;
    std::cout<<"Reproduciendo: "<<c1->siguiente->titulo<<std::endl;

    delete c1;
    delete c2;
    return 0;
};