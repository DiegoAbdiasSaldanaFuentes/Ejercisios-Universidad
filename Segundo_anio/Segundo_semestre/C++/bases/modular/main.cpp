#include <iostream>
#include "matematicas.h"

int main() {
    int x, y;
    std::cout << "Ingresa dos numeros: ";
    std::cin >> x >> y;

    std::cout << "Suma: " << sumar(x, y) << std::endl;
    std::cout << "Resta: " << restar(x, y) << std::endl;

    return 0;
}
