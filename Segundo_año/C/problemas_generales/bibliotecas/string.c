#include <stdio.h>
#include <string.h>


int main(){

    //Uso de StrLen
    char texto_len[]="Gandalf";
    int longitud_len;
    longitud_len=strlen(texto_len);

    //Uso de StrCpy
    char texto_cpy[]= "Este es un curso de C";
    char destino_cpy[50];
            //donde lo copiamos / que texto copiamos
    strcpy(destino_cpy,texto_cpy);

    //Uso de StrCat
    char nombre_completo_cat[50];
    char nombre[]="Gandalf";
    char apellido[]="el Gris";
                //destino / origen
    strcpy(nombre_completo_cat,nombre);
    strcat(nombre_completo_cat," "); // agregamos un espacio vacio para que haya un espacio al juntar nombre y apellido
    strcat(nombre_completo_cat,apellido);

    //Uso de Sprintf
    char nombre_completo_spr[50];
    char nombre_spr[]="Gandalf";
    char apellido_spr[]="el Gris";
                //destino / origen
    strcpy(nombre_completo_spr,nombre_spr);
    strcat(nombre_completo_spr," "); // agregamos un espacio vacio para que haya un espacio al juntar nombre y apellido
    strcat(nombre_completo_spr,apellido_spr);
    sprintf(nombre_completo_spr,"%s %s",nombre,apellido);

    //Uso de Strcmp
    char nombre_cmp1[]="Gandalf";
    char nombre_cmp2[]="Frodo";


    //Probar StrLen
    printf("La cadena %s tiene %i caracteres.\n",texto_len,longitud_len);
    //Probar StrCpy
    printf("Valor final:%s\n",destino_cpy);
    //Probar StrCat
    printf("El nombre completo es: %s.\n",nombre_completo_cat);
    //Probar Sprintf
    printf("El nombre completo es: %s.\n",nombre_completo_spr);
    //Probar Strcmp
    printf("Comparacion con strcmp: %i\n",strcmp(nombre_cmp1,nombre_cmp2));//Menor que 0 cadena1 menor que cadena   2, Mayor que 0 cadena1 mayor que cadena2, 0 cadenas iguales
}