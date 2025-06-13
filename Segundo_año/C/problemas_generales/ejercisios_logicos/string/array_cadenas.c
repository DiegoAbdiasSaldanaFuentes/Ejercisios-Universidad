#include <stdio.h>
#include <stdlib.h> 

int error(int num_err) {
    char *errores[] = {
        "No se ha producido ningún error",
        "No hay suficiente memoria",
        "No hay espacio en disco",
        "Me he cansado de trabajar"
    };
    int max_err = sizeof(errores) / sizeof(errores[0]);

    if (num_err < 0 || num_err >= max_err) {
        printf("Error desconocido: código %d fuera de rango.\n", num_err);
    } else {
        printf("Error número %d: %s.\n", num_err, errores[num_err]);
    }
    exit(-1);
}

int main() {
    error(2); 
}
