#include <omp.h>
#include <cstdio>

#define N 100


int main()
{
#pragma omp parallel for
    for (int i=0;i<N;i++)
        printf("%d,",i);


printf("\n");


/*Threads will need to wait before executing their chunk of iterations if
 previous iterations haven’t completed yet.*/
#pragma omp parallel for ordered
    for (int i=0;i<N;i++)
    {
        #pragma omp ordered   //This is essential, the next statement is ordered
        printf("%d,",i);
    }
printf("\n");
}
