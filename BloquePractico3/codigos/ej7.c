#include <stdio.h>
#include <stdlib.h>
#ifdef _OPENMP
#include <omp.h>
#else
#define omp_get_thread_num() 0
#endif
void main(int argc,char **argv) {
omp_sched_t kind;
int modifier;
omp_get_schedule(&kind,&modifier);
printf("run-sched-var=%d, %d\n",kind,modifier);
int N=atoi(argv[1]), i, j;
double t1,t2;
int *V;
V = (int *)malloc (N*sizeof(int));
int *V2;
V2 = (int *)malloc (N*sizeof(int));
int **M;
M = (int **)malloc (N*sizeof(int *));
for(i=0; i<N; i++)
M[i] = (int *)malloc (N*sizeof(int));
//Comprobamos que se dieron bien los parámetros
if(argc < 2) {
 fprintf(stderr,"Uso:./ejercicio8 N \n");
 exit(-1);
}
srand(time(0));
//Inicializamos M y V
#pragma omp parallel for schedule(runtime) private(j)
for(i=0; i<N; i++){
 for(j=0; j<i+1; j++){ M[i][j] = 1; }
}
#pragma omp parallel for schedule(runtime) 
for(i=0; i<N; i++){ V[i] = i+1; }

//Multiplicamos M x V = V2
t1 = omp_get_wtime();
#pragma omp parallel for schedule (runtime) private(j)
for(i=0; i<N; i++){
 V2[i] = 0;
 for(j=0; j<i+1; j++)
  V2[i] += M[i][j] * V[j];
}

t2 = omp_get_wtime();
t2 = t2-t1;
//Mostrar los resultados
if(N<10){
printf("M:\n");
for(i=0; i<N; i++){
for(j=0; j<N; j++)
printf("%d ",M[i][j]);
printf("\n");
}
printf("\nV:\n");
for(i=0; i<N; i++) printf("%d \n",V[i]);
printf("\nResultado MxV:\n");
for(i=0; i<N; i++) printf("%d ",V2[i]);
}
else{
printf("V2[0]:%d\n",V2[0]);
printf("V2[N-1]:%d\n",V2[N-1]);
}
printf("\nTiempo en ejecutar MxV:%8.7f\n",t2);
//Liberar memoria
for(i=0; i<N; i++)
free(M[i]);
free(M);
free(V);
free(V2);
}
