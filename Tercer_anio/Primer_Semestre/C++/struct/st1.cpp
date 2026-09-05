#include <iostream>
#include <string>

struct libreria {
    std::string isbn;
    std::string titulo;
    std::string autor;
    int can_pag;
    double precio;

};


int main(){
    //definir nuestro puntero
    libreria* libreria_puntero = new libreria;
    
    libreria_puntero->isbn = "10x00f";
    libreria_puntero->titulo = "Habitos Atomicos";
    libreria_puntero->autor = "Diego";
    libreria_puntero->can_pag = 210;
    libreria_puntero->precio = 10000;

    std::cout<<libreria_puntero->titulo<<std::endl;
    std::cout<<libreria_puntero->isbn<<std::endl;
    std::cout<<libreria_puntero->autor<<std::endl;
    std::cout<<libreria_puntero->can_pag<<std::endl;
    std::cout<<libreria_puntero->precio<<std::endl;

    delete libreria_puntero;
    libreria_puntero = nullptr;
    
    return 0;
};

