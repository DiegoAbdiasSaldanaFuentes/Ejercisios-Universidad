// codigo de ejemplo
#include <stdio.h>

int main() {
    FILE *archivo; // Puntero al archivo

    archivo = fopen("ejemplouno.txt", "r"); // Abrir en modo lectura ("r")

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1; // Código de error en caso que no encuentre el archivo que buscamos
    }

    char linea[100]; // Buffer para almacenar líneas

    while (fgets(linea, sizeof(linea), archivo)) {// la condicion es que mientras no entrege NULL osea que no haya nada seguira con el while
        printf("%s", linea); // Imprimir cada línea
    }

    fclose(archivo); // ¡Cierra siempre el archivo!
    return 0;
}

