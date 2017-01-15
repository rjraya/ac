#include <stdio.h>
#include <time.h> 
//producto A=B*C
unsigned int N = 1000;
 //If the array is declared as a global one or as static in a function, 
 //then all elements are initialized to zero if they aren't initialized already.
int A[1000][1000],B[1000][1000],C[1000][1000];
void main() {
		int i,j,k,i2,k2,j2;
		struct timespec cgt1,cgt2;
		double ncgt;
		clock_gettime(CLOCK_REALTIME,&cgt1);
		int SM = 4;
		int* rres;
		int* rmul1;
		int* rmul2;
		for (i = 0; i < N; i += SM)
			for (j = 0; j < N; j += SM)
				for (k = 0; k < N; k += SM)
					for (i2 = 0, rres = &A[i][j],rmul1 = &B[i][k]; i2 < SM;++i2, rres += N, rmul1 += N)
						for (k2 = 0, rmul2 = &C[k][j];k2 < SM; ++k2, rmul2 += N)
							for (j2 = 0; j2 < SM; ++j2)
								rres[j2] += rmul1[k2] * rmul2[j2];
		clock_gettime(CLOCK_REALTIME,&cgt2);
		ncgt=(double) (cgt2.tv_sec-cgt1.tv_sec)+(double) ((cgt2.tv_nsec-cgt1.tv_nsec)/(1.e+9));
//Imprimir resultados
		printf("Tiempo(seg.):%11.9f\t / Tamaño Vectores:%u\n",ncgt,N);
}
