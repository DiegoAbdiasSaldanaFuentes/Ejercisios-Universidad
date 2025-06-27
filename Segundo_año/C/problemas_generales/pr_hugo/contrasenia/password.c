/************************************************************************************************************************** 
 *  Autores: Diego Saldaña y Victor Farias                                                                                *
 *  Docente: Hugo Araya                                                                                              *
 *  Asignatura: Estructura de datos                                                                                       *
 *  Referencias bibliograficas: 'Programación en C de Byron Gottfried' y 'Brian W. Kernighan Dennis M. Ritchie'.          *
 *                                                                                                                        *                  
 *                                                                                                                        *
 *                                                                                                                        *                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
 *************************************************************************************************************************/
#include <stdio.h>
#include <string.h>

int tiene_consonante_oclusiva(char palabra[]);
int cumple_intercalado(char palabra[]);
int tiene_repeticion_invalida(char palabra[]);
int es_vocal(char letra);
int es_consonante(char letra);

int main(){
    FILE *ent, *sal;
    char palabra[100];
    ent = fopen("claves.txt", "r");
    sal = fopen("revisadas.txt", "w");

    while(fgets(palabra, sizeof(palabra), ent)) {
        palabra[strcspn(palabra, "\n")] = '\0';  
        if(strcmp(palabra, "end") == 0)
            break; 
        if(tiene_consonante_oclusiva(palabra) && cumple_intercalado(palabra) &&!tiene_repeticion_invalida(palabra)){
            fprintf(sal,"<%s> es aceptable\n", palabra);
        } 
        else{
            fprintf(sal, "<%s> no es aceptable\n", palabra);
        }
    }
    fclose(ent);
    fclose(sal);
    return 0;
}

int tiene_consonante_oclusiva(char palabra[]){
    int i;
    for (i = 0; palabra[i] != '\0'; i++) {
        if (palabra[i] == 'p' || palabra[i] == 't' || palabra[i] == 'k' || palabra[i] == 'b' || palabra[i] == 'd' || palabra[i] == 'g'){
            return 1;
        }
    }
    return 0;
}

int cumple_intercalado(char palabra[]){
    int i;
    for (i = 1; palabra[i] != '\0'; i++) {
        if ((es_vocal(palabra[i]) && es_vocal(palabra[i - 1])) || (es_consonante(palabra[i]) && es_consonante(palabra[i - 1]))){
            return 0;
        }
    }
    return 1;
}

int tiene_repeticion_invalida(char palabra[]) {
    int i;
    for (i = 1; palabra[i] != '\0'; i++) {
        if (palabra[i] == palabra[i - 1]) {
            if (!(palabra[i] == 'a' || palabra[i] == 'i')) {
                return 1;
            }
        }
    }
    return 0;
}

int es_vocal(char letra) {
    return (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u');
}
int es_consonante(char letra) {
    return (letra >= 'a' && letra <= 'z') && !es_vocal(letra);
}