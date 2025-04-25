/*Los números a y b son enteros positivos. Calcular a elevado a b sin usar
potenciación. 
*/

int main(){
    intverdura, empaque;
    verdura =1;
    while(verdura <= 10){
        empaque =1;
        while(empaque <= 10){
            printf("verdura %d- empaque %s\n",verdura,empaque);
            empaque++;
        }
        verdura++;
    }
    return 0;
}