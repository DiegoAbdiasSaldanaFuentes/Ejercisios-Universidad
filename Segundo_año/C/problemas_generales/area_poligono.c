#include <stdio.h>

float calcular_area(int tipo, float base, float altura);

int main() {
    int opcion;
    float base, altura;

    printf("Elige el polígono:\n");
    printf("1. Triangulo\n2. Rectangulo\n3. Cuadrado\n");
    scanf("%d", &opcion);

    if (opcion == 1 || opcion == 2) {
        printf("Ingrese la base: ");
        scanf("%f", &base);
        printf("Ingrese la altura: ");
        scanf("%f", &altura);
    } else if (opcion == 3) {
        printf("Ingrese el lado del cuadrado: ");
        scanf("%f", &base);
        altura = base; // El cuadrado tiene lados iguales
    } else {
        printf("Opcion invalida.\n");
        return 1;
    }

    float area = calcular_area(opcion, base, altura);
    printf("El area del poligono es: %.2f\n", area);

    return 0;
}

// Única función para calcular área de cualquier polígono soportado
float calcular_area(int tipo, float base, float altura) {
    if (tipo == 1) { // Triángulo
        return (base * altura) / 2;
    } else if (tipo == 2) { // Rectángulo
        return base * altura;
    } else if (tipo == 3) { // Cuadrado
        return base * base;
    } else {
        return -1; // Código de error
    }
}
