#include <stdio.h>
#include <stdlib.h>
#ifdef _OPENMP
#include <omp.h>
#else
#define omp_get_thread_num() 0
#endif
void main(int argc,char **argv) {

int N=atoi(argv[1]), i, j, k;
double t1,t2;
int **M;
M = (int **)malloc (N*sizeof(int *));
for(i=0; i<N; i++)
M[i] = (int *)malloc (N*sizeof(int));
int **M1;
M1 = (int **)malloc (N*sizeof(int *));
for(i=0; i<N; i++)
M1[i] = (int *)malloc (N*sizeof(int));
int **M2;
M2 = (int **)malloc (N*sizeof(int *));
for(i=0; i<N; i++)
M2[i] = (int *)malloc (N*sizeof(int));
omp_sched_t kind;
int modifier;
omp_get_schedule(&kind,&modifier);
printf("run-sched-var=%d, %d\n",kind,modifier);
//Comprobamos que se dieron bien los parámetros
if(argc < 2) {
fprintf(stderr,"Uso:./pmm-secuencial N \n");
exit(-1);
}
srand(time(0));
//Inicializamos M1 y M2	
#pragma omp parallel for private(j) schedule(runtime)
for(i=0; i<N; i++)
 for(j=0; j<N; j++){ M1[i][j] = i*j+1; }
#pragma omp parallel for private(j) schedule(runtime)
for(i=0; i<N; i++)
 for(j=0; j<N; j++){ M2[i][j] = 1; }
//Multiplicamos M1 x M2 = M
t1=omp_get_wtime();
#pragma omp parallel for private(j) schedule(runtime)
for(i=0;i<N;i++){
 #pragma omp parallel for private(k) schedule(runtime)
 for(j=0;j<N;j++) {
  for(k=0;k<N;k++) {M[i][j]=M[i][j]+M1[i][k]*M2[k][j];}
 }
}
t2 = omp_get_wtime();
t2 = t2-t1;
//Mostrar los resultados
if(N<10){
 printf("M1:\n");
for(i=0; i<N; i++){
 for(j=0; j<N; j++){ printf("%d ",M1[i][j]); }
 printf("\n");
}

printf("M2:\n");
for(i=0; i<N; i++){
 for(j=0; j<N; j++){printf("%d ",M2[i][j]);}
 printf("\n");
}

printf("\nResultado M1xM2:\n");
for(i=0; i<N; i++){
 for(j=0; j<N; j++){printf("%d ",M[i][j]);}
 printf("\n");
}
}else{
 printf("M[0][0]:%d\n",M[0][0]);
 printf("M[N-1][N-1]:%d\n",M[N-1][N-1]);
}
printf("\nTiempo en ejecutar M1xM2:%8.7f\n",t2);
//Liberar memoria
for(i=0; i<N; i++)
 free(M1[i]);
free(M1);
for(i=0; i<N; i++)
 free(M2[i]);
free(M2);
for(i=0; i<N; i++)
 free(M[i]);
free(M);
}


