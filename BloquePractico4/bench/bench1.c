#include <stdlib.h>
#include <stdio.h>
#include <time.h> 

//The C language does not have a global keyword. However, variables declared outside a function have "file scope," 
//meaning they are visible within the file. Variables declared with file scope are visible between their declaration
//and the end of the compilation unit
struct {
 int a;
 int b;
} s[5000];


main()
{
 //Array con los resultados. Orden de preferencia: local, global, puntero.
 int R[40000]; 
 int ii,i;
 int X1,X2;

 //Para medir el tiempo de ejecución
 double ncgt; 
 struct timespec cgt1,cgt2;

//La inicializacion no cuenta
 for(i=0; i<5000; i++){
  s[i].a=2;
  s[i].b=3;
 }
    
 clock_gettime(CLOCK_REALTIME,&cgt1);
 for (ii=1; ii<=40000;ii++) {
  X1=0; X2=0;
  for(i=0; i<5000;i++) X1+=2*s[i].a+ii;
  for(i=0; i<5000;i++) X2+=3*s[i].b-ii;

  if (X1<X2) R[ii]=X1; else R[ii]=X2;
 } 
 clock_gettime(CLOCK_REALTIME,&cgt2);
 ncgt=(double) (cgt2.tv_sec-cgt1.tv_sec)+(double) ((cgt2.tv_nsec-cgt1.tv_nsec)/(1.e+9));
 printf("Tiempo(seg.):%11.9f \n",ncgt);
}