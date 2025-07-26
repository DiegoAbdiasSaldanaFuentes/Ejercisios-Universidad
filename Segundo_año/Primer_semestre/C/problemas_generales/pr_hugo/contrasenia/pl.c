#include <stdio.h>
#include <string.h>

int verificacion(char palabra[], FILE *salida);

int main() {
    FILE *entrada, *salida;
    char palabra[100];

    entrada = fopen("claves.txt", "r");
    salida = fopen("revisadas.txt", "w");

    fgets(palabra, sizeof(palabra), entrada);
    palabra[strcspn(palabra, "\n")] = '\0';

    while (strcmp(palabra, "end") != 0) {
        verificacion(palabra, salida);

        fgets(palabra, sizeof(palabra), entrada);
        palabra[strcspn(palabra, "\n")] = '\0';
    }

    fclose(entrada);
    fclose(salida);
    return 0;
}

int verificacion(char palabra[], FILE *salida) {
    int i;
    int tiene_oclusiva = 0;
    int intercalado_mal = 0;
    int repeticion_mal = 0;

    // Revisa si tiene consonante oclusiva
    for (i = 0; palabra[i] != '\0'; i++) {
        if (palabra[i] == 'p' || palabra[i] == 't' || palabra[i] == 'k' ||
            palabra[i] == 'b' || palabra[i] == 'd' || palabra[i] == 'g') {
            tiene_oclusiva = 1;
        }
    }

    // Revisa si hay dos vocales o dos consonantes seguidas
    for (i = 1; palabra[i] != '\0'; i++) {
        char a = palabra[i - 1];
        char b = palabra[i];
        int a_es_vocal = (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u');
        int b_es_vocal = (b == 'a' || b == 'e' || b == 'i' || b == 'o' || b == 'u');
        if ((a_es_vocal && b_es_vocal) || (!a_es_vocal && !b_es_vocal)) {
            intercalado_mal = 1;
        }
    }

    for (i = 1; palabra[i] != '\0'; i++) {
        if (palabra[i] == palabra[i - 1]) {
            if (palabra[i] != 'a' && palabra[i] != 'i') {
                repeticion_mal = 1;
            }
        }
    }
    if (tiene_oclusiva == 1 && intercalado_mal == 0 && repeticion_mal == 0) {
        fprintf(salida, "<%s> es aceptable\n", palabra);
    } else {
        fprintf(salida, "<%s> no es aceptable\n", palabra);
    }

    return 0;
}
