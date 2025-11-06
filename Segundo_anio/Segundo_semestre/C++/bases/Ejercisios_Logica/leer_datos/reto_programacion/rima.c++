#include <iostream>
#include <string.h>

int main(){
    char string1[] = "hola";
    char string2[] = "holas";

    int num_len1 = strlen(string1);
    int num_len2 = strlen(string2);

    int mayor (num_len1 > num_len2 ? num_len1 : num_len2);

    std::cout<<mayor;

    return 0;
}