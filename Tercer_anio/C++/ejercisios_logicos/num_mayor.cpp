/**************************************************************
 * Nombre: Diego Saldaña
 * Ejercisio: Tres números A,B,C indicar cual es mayores
 * 
 ***************************************************************/

#include <iostream>


int main(){
    int num;
    int num2;
    int num3;

    //Inputs
    std::cout<<"Ingresa el primer numero:";
    std::cin>>num;

    std::cout<<"Ingresa el segundo numero:";
    std::cin>>num2;

    std::cout<<"Ingresa el tercer numero:";
    std::cin>>num3;

    //Validacion
    if(num >num2){
        if(num >num3){
            std::cout<<"el numero mas grande es "<<num<<std::endl;
        }else{
            std::cout<<"el numero mas grande es "<<num3<<std::endl;
        }
    }else{
        if(num2 >num3){
            std::cout<<"el numero mas grande es "<<num2<<std::endl;
        }else{
            std::cout<<"el numero mas grande es "<<num3<<std::endl;
        }

    }
    return 0;
};
