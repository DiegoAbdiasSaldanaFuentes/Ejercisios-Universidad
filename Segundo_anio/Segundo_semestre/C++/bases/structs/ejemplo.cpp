#include <iostream>
#include <string>

struct Producto{
    int id;
    std::string nombre;
    double precio; 
};


int main(){

    Producto* miPuntero = nullptr;
    miPuntero = new Producto;
    
    return 0;
}