#include<stdio.h> 
#include<stdlib.h> 

struct tpila{
    int dato; 
    struct tpila *sig; 
}; 
void crear(struct tpila **pila);
int vacia(struct tpila *pila);
void push(struct tpila *pila, int elem);
void pop(struct tpila *pila, char *elem);


int main(void){ 
    struct tpila *dato; 
    char elem, sale; 
        FILE *ent; 
        ent = fopen("a_revisar.txt","rt"); 
        while (!feof(ent)){ 
            elem=fgetc(ent); 
            printf ("\nLeido %c",elem); 
            if (elem=='{') 
                push(dato, elem); 
            else 
                if (elem=='}') { 
                    if (vacia(dato)) { 
                        printf("\nError 1: Falta {\n"); 
                        exit(0); 
                    } 
                    pop(dato, &elem); 
                } 
    } 
    if (vacia(dato)) 
        printf("\nNo hay Error\n"); 
    else 
        printf("\nError 2: Falta }\n"); 
    fclose(ent); 
    return 0; 
}

void crear(struct tpila **pila) { 
    *pila = (struct tpila *) malloc(sizeof(struct tpila)); 
    (*pila)->sig = NULL; 
} 

int vacia(struct tpila *pila){ 
    return (pila->sig == NULL); 
}

void push(struct tpila *pila, int elem){ 
    struct tpila *nuevo; 
    nuevo = (struct tpila *) malloc(sizeof(struct tpila)); 
    nuevo->dato = elem; 
    nuevo->sig = pila->sig; 
    pila->sig = nuevo; 
} 

void pop(struct tpila *pila, char *elem){ 
    struct tpila *aux; 
    aux = pila->sig; 
    *elem = aux->dato; 
    pila->sig = aux->sig; 
    free(aux); 
}