#include<stdio.h> 

int main(int argc, char *argv[]){ 
    struct tpila *pila; 
    char elem,sale; 
    FILE *ent; 
    ent = fopen(argv[1],"rt"); 
    while (!feof(ent)) { 
        elem=fgetc(ent); 
        if (elem=='{') 
    push(pila, elem); 
    else 
    if (elem=='}'){ 
    if (vacia(pila))    
    printf("\nError: Falta {\n"); 
    exit(0); 
    } 
    pop(pila,&sale); 
    } 
} 
if (vacia(pila)) 
printf("\nNo hay Error\n"); 
else 
{ 
23 
printf("\nError: Falta }\n"); 
return 0;