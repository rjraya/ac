#include <stdio.h>
#include <math.h>
#include <time.h>
long k,m=1000,n=1000,l=1000,i,j;

int a[1000][1000],b[1000][1000],c[1000][1000];

int main()
{	
	 struct timespec cgt1,cgt2;
    double ncgt;
    clock_gettime(CLOCK_REALTIME,&cgt1);
    double tmp[1000][1000];
    for (i=0;i<1000;++i)//trasponemos C
      for (j = 0; j < 1000; ++j)
        tmp[i][j] = b[j][i];
	for (k=0;k<n;k+=10)
		for (i=0;i<l;i++)
		{	
			for (j=0;j<m;j++){
				c[k][i]+= a[k][j]*b[j][i];
				c[k+1][i]+= a[k+1][j]*tmp[i][j];
				c[k+2][i]+= a[k+2][j]*tmp[i][j];
				c[k+3][i]+= a[k+3][j]*tmp[i][j];
				c[k+4][i]+= a[k+4][j]*tmp[i][j];
				c[k+5][i]+= a[k+5][j]*tmp[i][j];
				c[k+6][i]+= a[k+6][j]*tmp[i][j];
				c[k+7][i]+= a[k+7][j]*tmp[i][j];
				c[k+8][i]+= a[k+8][j]*tmp[i][j];
				c[k+9][i]+= a[k+9][j]*tmp[i][j];
			}
		}
		
	clock_gettime(CLOCK_REALTIME,&cgt2);
		ncgt=(double) (cgt2.tv_sec-cgt1.tv_sec)+(double) ((cgt2.tv_nsec-cgt1.tv_nsec)/(1.e+9));
//Imprimir resultados
		printf("Tiempo(seg.):%11.9f\t / Tamaño Vectores:%u\n",ncgt,1000);

	return 0;
}
