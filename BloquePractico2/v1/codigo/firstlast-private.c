#include <stdio.h>
#include <stdlib.h>
#ifdef _OPENMP
#include <omp.h>
#else
#define omp_get_thread_num() 0
#endif
main(int argc, char** argv) {
int i, n=10,suma=0,chunk;
int a[n];

if(argc < 2){
	fprintf(stderr,"Falta chunk");
}
chunk = atoi(argv[1]);

for (i=0; i<n; i++) a[i] = i;
#pragma omp parallel for firstprivate(suma) lastprivate(suma) schedule(static,chunk)
for (i=0;i<n; i++){
 suma += a[i];
 printf("thread %d suma a[%d] suma=%d \n",omp_get_thread_num(),i,suma);
}

printf("\nFuera de la construcción parallel suma=%d\n",suma);
}
