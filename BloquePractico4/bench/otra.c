#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
struct str{
	int a;
	int b;
};
struct str s[500];

long ii,i;
int main()
{	double ncgt; 
 struct timespec cgt1,cgt2;
clock_gettime(CLOCK_REALTIME,&cgt1);
	/* ---------- Algoritmo a ejecutar -------------- */
	for (ii=1;ii<=1000000;ii+=5)
	{	for ( i=0;i<100;i+=5){
			s[i].a=s[i].a+s[i].a;
			s[i+1].a=s[i+1].a+s[i+1].a;
			s[i+2].a=s[i+2].a+s[i+2].a;
			s[i+3].a=s[i+3].a+s[i+3].a;
			s[i+4].a=s[i+4].a+s[i+4].a;
		}
		for (i=0;i<100;i+=5){
			s[i].b=s[i].b*3;
			s[i+1].b=s[i+1].b*3;
			s[i+2].b=s[i+2].b*3;
			s[i+3].b=s[i+3].b*3;
			s[i+4].b=s[i+4].b*3;
		}
		for ( i=0;i<100;i+=5){
			s[i].a=s[i].a+s[i].a;
			s[i+1].a=s[i+1].a+s[i+1].a;
			s[i+2].a=s[i+2].a+s[i+2].a;
			s[i+3].a=s[i+3].a+s[i+3].a;
			s[i+4].a=s[i+4].a+s[i+4].a;
		}
		for (i=0;i<100;i+=5){
			s[i].b=s[i].b*3;
			s[i+1].b=s[i+1].b*3;
			s[i+2].b=s[i+2].b*3;
			s[i+3].b=s[i+3].b*3;
			s[i+4].b=s[i+4].b*3;
		}
		for ( i=0;i<100;i+=5){
			s[i].a=s[i].a+s[i].a;
			s[i+1].a=s[i+1].a+s[i+1].a;
			s[i+2].a=s[i+2].a+s[i+2].a;
			s[i+3].a=s[i+3].a+s[i+3].a;
			s[i+4].a=s[i+4].a+s[i+4].a;
		}
		for (i=0;i<100;i+=5){
			s[i].b=s[i].b*3;
			s[i+1].b=s[i+1].b*3;
			s[i+2].b=s[i+2].b*3;
			s[i+3].b=s[i+3].b*3;
			s[i+4].b=s[i+4].b*3;
		}
		for ( i=0;i<100;i+=5){
			s[i].a=s[i].a+s[i].a;
			s[i+1].a=s[i+1].a+s[i+1].a;
			s[i+2].a=s[i+2].a+s[i+2].a;
			s[i+3].a=s[i+3].a+s[i+3].a;
			s[i+4].a=s[i+4].a+s[i+4].a;
		}
		for (i=0;i<100;i+=5){
			s[i].b=s[i].b*3;
			s[i+1].b=s[i+1].b*3;
			s[i+2].b=s[i+2].b*3;
			s[i+3].b=s[i+3].b*3;
			s[i+4].b=s[i+4].b*3;
		}
		for ( i=0;i<100;i+=5){
			s[i].a=s[i].a+s[i].a;
			s[i+1].a=s[i+1].a+s[i+1].a;
			s[i+2].a=s[i+2].a+s[i+2].a;
			s[i+3].a=s[i+3].a+s[i+3].a;
			s[i+4].a=s[i+4].a+s[i+4].a;
		}
		for (i=0;i<100;i+=5){
			s[i].b=s[i].b*3;
			s[i+1].b=s[i+1].b*3;
			s[i+2].b=s[i+2].b*3;
			s[i+3].b=s[i+3].b*3;
			s[i+4].b=s[i+4].b*3;
		}
	}
	/* ------------ Final del Algoritmo -------------- */
 clock_gettime(CLOCK_REALTIME,&cgt2);
 ncgt=(double) (cgt2.tv_sec-cgt1.tv_sec)+(double) ((cgt2.tv_nsec-cgt1.tv_nsec)/(1.e+9));
 printf("Tiempo(seg.):%11.9f \n",ncgt);
	return 0;
}

