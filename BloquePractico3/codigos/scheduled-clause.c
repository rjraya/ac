#include <stdio.h>
#include <stdlib.h>
#ifdef _OPENMP
 #include <omp.h>
#else
 #define omp_get_thread_num() 0
#endif
main(int argc, char **argv) {
 int i, n = 7,chunk, a[n],suma=0;
 omp_sched_t kind;
 int modifier;

 if(argc < 2) {
  fprintf(stderr,"\nFalta chunk \n");
  exit(-1);
 }
 chunk = atoi(argv[1]);
 for (i=0; i<n; i++) a[i] = i;

#pragma omp parallel for firstprivate(suma) lastprivate(suma) schedule(dynamic,chunk)
for (i=0; i<n; i++)
{ 
  suma = suma + a[i];
  printf(" thread %d suma a[%d] suma=%d \n",omp_get_thread_num(),i,suma);
  if(i == n-1){
    omp_get_schedule(&kind, &modifier);
  //  printf("Dentro de 'parallel' dyn-var=%d \n",omp_get_dynamic());
  //  printf("Dentro de 'parallel' nthreads-var:%d \n",omp_get_max_threads());
  //  printf("Dentro de 'parallel' thread-limit-var:%d \n",omp_get_thread_limit());
  //  printf("Dentro de 'parallel' run-sched-var (kind,modifier):%d,%d \n",kind,modifier);
  //  printf("Dentro de 'parallel' num_threads=%d \n",omp_get_num_threads());
  //  printf("Dentro de 'parallel' num_procs=%d \n",omp_get_num_procs());
  //  printf("Dentro de 'parallel' in_parallel=%d \n",omp_in_parallel());
  }
 } 

 //printf("Fuera de 'parallel' suma=%d\n",suma);
 //printf("Fuera de 'parallel' dyn-var=%d \n",omp_get_dynamic());
 //printf("Fuera de 'parallel' nthreads-var:%d \n",omp_get_max_threads());
 //printf("Fuera de 'parallel' thread-limit-var:%d \n",omp_get_thread_limit());
 //omp_get_schedule(&kind, &modifier);
 //printf("Fuera de 'parallel' run-sched-var (kind,modifier):%d,%d \n",kind,modifier);
 //printf("Fuera de 'parallel' num_threads=%d \n",omp_get_num_threads());
 //printf("Fuera de 'parallel' num_procs=%d \n",omp_get_num_procs());
 //printf("Fuera de 'parallel' in_parallel=%d \n",omp_in_parallel());

 //Si los dynamic_threads se evalúan como un valor distinto de cero, el número de subprocesos que se utilizan para 
 //ejecutar las regiones paralelas subsiguientes se puede ajustar automáticamente 
 printf("Antes de modificar dyn-var=%d \n",omp_get_dynamic());
 omp_set_dynamic(0);
 printf("Despues de modificar dyn-var=%d \n",omp_get_dynamic());
 printf("Antes de modificar nthreads-var:%d \n",omp_get_max_threads());
 omp_set_num_threads(10);
 printf("Despues de modificar nthreads-var:%d \n",omp_get_max_threads());
 printf("Antes de modificar run-sched-var (kind,modifier):%d,%d \n",kind,modifier);
 omp_set_schedule(omp_sched_guided,1);
 printf("Despues de modificar run-sched-var (kind,modifier):%d,%d \n",kind,modifier);
}
