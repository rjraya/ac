#include <stdio.h>
#include <math.h>
#include <time.h>
long k=1000,N=1000,i,j;

int a[1000][1000],b[1000][1000],c[1000][1000];

int main()
{ 
   struct timespec cgt1,cgt2;
    double ncgt;
    clock_gettime(CLOCK_REALTIME,&cgt1);
  for (i=0;i<N;i+=5){
    for (j=0;j<N;j++){
      for (k=0;k<N;k++){
        c[i][j]+= a[i][k]*b[k][j];
        c[i+1][j]+= a[i+1][k]*b[k][j];
        c[i+2][j]+= a[i+2][k]*b[k][j];
        c[i+3][j]+= a[i+3][k]*b[k][j];
        c[i+4][j]+= a[i+4][k]*b[k][j];
      }
    }
  }
    
  clock_gettime(CLOCK_REALTIME,&cgt2);
    ncgt=(double) (cgt2.tv_sec-cgt1.tv_sec)+(double) ((cgt2.tv_nsec-cgt1.tv_nsec)/(1.e+9));
//Imprimir resultados
    printf("Tiempo(seg.):%11.9f\t / Tamaño Vectores:%u\n",ncgt,1000);

  return 0;
}
