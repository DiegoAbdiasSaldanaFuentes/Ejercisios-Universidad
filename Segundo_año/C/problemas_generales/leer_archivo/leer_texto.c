// codigo de ejemplo
#include <stdio.h>

int main() {
    FILE *archivo; 
    archivo = fopen("ejemplouno.txt", "r"); 
    char linea[100]; 

    while (fgets(linea, sizeof(linea), archivo)) {
    }
    fclose(archivo); 
    return 0;
}

