#include <stdio.h>
#include <time.h> 
//producto A=B*C
unsigned int N = 1000;
 //If the array is declared as a global one or as static in a function, 
 //then all elements are initialized to zero if they aren't initialized already.
int A[1008][1008] __attribute__ ((aligned (16)));
int B[1008][1008] __attribute__ ((aligned (16)));
int C[1008][1008] __attribute__ ((aligned (16)));
void main() {
    int i,j,k;
    struct timespec cgt1,cgt2;
    double ncgt;
    clock_gettime(CLOCK_REALTIME,&cgt1);
    int tmp[N][N];
    for (i=0;i<N;++i)//trasponemos C
      for (j = 0; j < N; ++j)
        tmp[i][j] = C[j][i];

    for (i=0;i<N;i++){
     for (j=0;j<N;j++){
      for (k=0;k<N;k++){
        
        /* //Proyecto futuro de ensamblador como adaptarlo a int?
       asm( "mov esi\n
        dword ptr [pA]\n
       mov edi, dword ptr [pC]\n
      mov ecx, N\n
      L3:
        push ecx
        mov ecx, N
        mov ebx, dword ptr [pB]     // We will be  going through every column of B (NChunk * 16 = 1 Column)
        L2:
          subss xmm1,xmm1       // clear xmm2 - Accumulator of Dot Product chunks
          push esi          // save esi
          push ecx
          mov ecx, NChunk
          L1:
            movups xmm0, [esi]
            dpps xmm0, [ebx], 0xFF  // Dot Product Instruction SSE4
            addss xmm1, xmm0
            add ebx, 16
            add esi, 16
          Loop L1
          movss dword ptr[edi], xmm1  // We will have one entry in result
          add edi, 4
          pop ecx
          pop esi           // restore esi because still in the same row in A
        Loop L2             // We will have one row in result
        add esi, NRow
        pop ecx
      Loop L3");
           asm("push        %ebx  \n" // clobber
" mov  8(%ebp), %ebx  \n"
" mov 12(%ebp), %ecx  \n"
"       \n"
" mov $0, %eax    \n"
" mov $0, %edx    \n"
"bucle:       \n"
" add (%ebx,%edx,4), %eax \n"
" inc       %edx    \n"
" cmp  %edx,%ecx    \n"
" jne bucle   \n"
"       \n"
" pop  %ebx   \n"
//   :        // output
//   :        // input
//   : "cc",      // clobber
//     "eax","ebx","ecx","edx"
    );
        //C[i][j]+= A[i][k]*tmp[j][k];
        //C[i+1][j]+= A[i+1][k]*tmp[j][k];
        //C[i+2][j]+= A[i+2][k]*tmp[j][k];
        //C[i+3][j]+= A[i+3][k]*tmp[j][k];
      }
    }
  }*/
    clock_gettime(CLOCK_REALTIME,&cgt2);
    ncgt=(double) (cgt2.tv_sec-cgt1.tv_sec)+(double) ((cgt2.tv_nsec-cgt1.tv_nsec)/(1.e+9));
//Imprimir resultados
    printf("Tiempo(seg.):%11.9f\t / Tamaño Vectores:%u\n",ncgt,N);
}
