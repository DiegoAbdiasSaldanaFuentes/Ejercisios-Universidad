#include<stdio.h> 

enum dias{
    Lunes,
    Martes,
    Miercoles
};

int main(){
    enum dias p=Lunes;
    printf("%d",p);
    return 0;
}