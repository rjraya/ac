#include <stdio.h>
#include <time.h> 
//producto A=B*C
unsigned int N = 1000;
 //If the array is declared as a global one or as static in a function, 
 //then all elements are initialized to zero if they aren't initialized already.
int A[1008][1008] __attribute__ ((aligned (16)));
int B[1008][1008] __attribute__ ((aligned (16)));
int C[1008][1008] __attribute__ ((aligned (16)));
void main() {
    int i,j,k,tmp;
    struct timespec cgt1,cgt2;
    double ncgt;
    clock_gettime(CLOCK_REALTIME,&cgt1);
    for (i=0;i<N;++i)//trasponemos C
      for (j = 0; j < N; ++j){
        tmp = C[j][i];
        C[j][i] = C[i][j];
        C[i][j] = tmp;
      }

    for (i=0;i<N;i+=16){
     for (j=0;j<N;j++){
      for (k=0;k<N;k++){
        C[i][j]+= A[i][k]*C[j][k];
        C[i+1][j]+= A[i+1][k]*C[j][k];
        C[i+2][j]+= A[i+2][k]*C[j][k];
        C[i+3][j]+= A[i+3][k]*C[j][k];
        C[i+4][j]+= A[i+4][k]*C[j][k];
        C[i+5][j]+= A[i+5][k]*C[j][k];
        C[i+6][j]+= A[i+6][k]*C[j][k];
        C[i+7][j]+= A[i+7][k]*C[j][k];
        C[i+8][j]+= A[i+8][k]*C[j][k];
        C[i+9][j]+= A[i+9][k]*C[j][k];
        C[i+10][j]+= A[i+10][k]*C[j][k];
        C[i+11][j]+= A[i+11][k]*C[j][k];
        C[i+12][j]+= A[i+12][k]*C[j][k];
        C[i+13][j]+= A[i+13][k]*C[j][k];
        C[i+14][j]+= A[i+14][k]*C[j][k];
        C[i+15][j]+= A[i+15][k]*C[j][k];
      }
    }
  }
    clock_gettime(CLOCK_REALTIME,&cgt2);
    ncgt=(double) (cgt2.tv_sec-cgt1.tv_sec)+(double) ((cgt2.tv_nsec-cgt1.tv_nsec)/(1.e+9));
//Imprimir resultados
    printf("Tiempo(seg.):%11.9f\t / Tamaño Vectores:%u\n",ncgt,N);
}
