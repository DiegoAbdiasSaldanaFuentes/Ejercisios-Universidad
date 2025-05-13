//Invirtiendo decimales
//tecnica usada extraccion de digitos
/*cuando  usar esto: 
-Extraer los dígitos de un número.
-Ivertir un número.
-Contar cuántos dígitos tiene un número.
-Verificar si un número es palíndromo (igual al derecho y al revés).
-Realizar operaciones dígito a dígito, como sumar dígitos, invertir, detectar múltiplos, etc.*/
#include <stdio.h>
int main() {
    int a = 1234;


    printf("Número invertido: ");
    while (a > 0) {
        int digito = a % 10;
        printf("%d", digito);
        a= a/10;
    }


    return 0;
}
