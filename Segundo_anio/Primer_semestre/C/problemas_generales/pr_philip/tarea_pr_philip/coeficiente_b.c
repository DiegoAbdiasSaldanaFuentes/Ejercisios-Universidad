/*************************************************************************
 *  Autor: Diego Saldaña                                                 *
 *  Docente: Philip Vásquez                                              *                    
 *  Enunciado: Poder crear un programa que puede entregar el resultado   *
 *  del coeficiente binominial.                                          *
 *  Fecha: 19-06-2025                                                    *                
 *                                                                       *                                                                      
 *************************************************************************/
#include <stdio.h>

int coeficiente_binominial(int m ,int n, int num);
int factorial1(int num_a);
int factorial2(int num_b);
int factorial3(int num);

int main(){
    int m=5,n=3; // Respuesta 10
    int resta= m-n;
    int fac_num1 =factorial1(m);
    printf("factorial 1: %d\n",fac_num1);
    int fac_num2 =factorial2(n);
    printf("factorial 2: %d\n",fac_num2);
    int fac_num3 = factorial3(resta);
    printf("factorial 3: %d\n",fac_num3);
    int cb = coeficiente_binominial(fac_num1,fac_num2,resta);
    return 0;
}


int factorial1(int num_a) {
    if (num_a == 0 || num_a == 1) {
        return 1;
    }
    else if(num_a==2){
        return 2;
    } 
    else {
        return num_a * factorial1(num_a - 1); 
    }
}
int factorial2(int num_b) {
    if (num_b == 0 || num_b == 1) {
        return 1; 
    }
    else if(num_b==2){
        return 2;
    } 
    else {
        return num_b * factorial2(num_b - 1); 
    }
}
int factorial3(int num) {
    if (num == 0 || num == 1) {
        return 1; 
    }
    else if(num==2){
        return 2;
    } 
    else {
        return num * factorial2(num - 1); 
    }
}



int coeficiente_binominial(int m,int n,int num){
    int resultado= m/(n*num);
    printf("Resultado: %d\n",resultado);   
    return resultado;
}