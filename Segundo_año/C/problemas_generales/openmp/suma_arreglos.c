#include <omp.h>
#include <stdio.h>
//modo normal
//int main(){
//    int num_array1[]={1,2,3,4,5,6};
//    int num_array2[]={1,2,3,4,5,6};
//    for(int i=0;i<6;i++){
//        int num_resultado= num_array1[i]+num_array2[i];
//        printf("%d\n",num_resultado);
//    }
//    return 0;
//}

//modo omp
int main (){
    int num_threads = 20; // Por ejemplo, configurar 6 hilos
    omp_set_num_threads(num_threads);//Quiero usar 6 hilos cuando entre en una región paralela
    int num_array1[]={1,2,3,4,5,6};
    int num_array2[]={1,2,3,4,5,6};
    #pragma omp parallel for//“A partir de aquí, ejecuta este bloque con múltiples hilos.”,  realiza el bucle  con cada hilo
    

    for(int i=0;i<6;i++){
        int num_resultado= num_array1[i]+num_array2[i];
        printf("%d\n",num_resultado);
        }
    
    return 0;
}
