#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char** argv)
{	
	long N = atoi(argv[1]);
	double *x;
    x = (double *)malloc (N*sizeof(int));
    double *y;
    y = (double *)malloc (N*sizeof(int));
    double a;
    int i;
	double ncgt; 
    struct timespec cgt1,cgt2;
	clock_gettime(CLOCK_REALTIME,&cgt1);
	//Algoritmo
	for (i=0;i<N;i++){ y[i]=y[i]+a*x[i];}
	

    clock_gettime(CLOCK_REALTIME,&cgt2);
	ncgt=(double) (cgt2.tv_sec-cgt1.tv_sec)+(double) ((cgt2.tv_nsec-cgt1.tv_nsec)/(1.e+9));
    printf("Tiempo(seg.):%11.9f \n",ncgt);
    free(x);
    free(y);
	return 0;
}
