#include <omp.h>
#include <stdio.h>

int main(){
    int numproceso = omp_get_num_procs();
    printf("numero de nucleos detectados por el sistema: %d\n",numproceso);
    return 0;
}