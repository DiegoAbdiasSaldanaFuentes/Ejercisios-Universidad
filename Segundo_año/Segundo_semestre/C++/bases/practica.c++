#include <iostream>
#include <string>

int main() {
    std::cout << "Hola Mundo" << std::endl;

    auto saludar = "Hola, Mundo"; // const char*
    std::cout << saludar << std::endl;

    char nombre[] = "Diego con nombre[]"; // estilo C
    std::cout << nombre << std::endl;

    std::string nombre_a = "Diego con std::string"; // estilo moderno
    std::cout << nombre_a << std::endl;

    const char* puntero_literal = "Cadena como const char*"; // literal de cadena
    std::cout << puntero_literal << std::endl;

    auto desde_auto = std::string("Auto con string");
    std::cout << desde_auto << std::endl;

    std::string concatenado = std::string("Hola ") + nombre_a;
    std::cout << concatenado << std::endl;

    return 0;
}
