#include <stdio.h>
#include <time.h> 
//producto A=B*C
unsigned int N = 1000;
 //If the array is declared as a global one or as static in a function, 
 //then all elements are initialized to zero if they aren't initialized already.
int A[1000][1000],B[1000][1000],C[1000][1000];
void main() {
    int i,j,k;
    struct timespec cgt1,cgt2;
    double ncgt;
    clock_gettime(CLOCK_REALTIME,&cgt1);
    for (i = 0; i < N; ++i)
      for (j = 0; j < N; ++j)
        for (k = 0; k < N; ++k)
          A[i][j] += B[i][k] * C[k][j];
    clock_gettime(CLOCK_REALTIME,&cgt2);
    ncgt=(double) (cgt2.tv_sec-cgt1.tv_sec)+(double) ((cgt2.tv_nsec-cgt1.tv_nsec)/(1.e+9));
//Imprimir resultados
    printf("Tiempo(seg.):%11.9f\t / Tamaño Vectores:%u\n",ncgt,N);
}
