#include <omp.h>
#include <cstdio>

#define N 10000


int main()
{
    int tot=0;
#pragma omp parallel for shared(tot)
    for (int i=0;i<N;i++)
        tot++;

printf("Total: %d\n",tot);

    tot = 0;
#pragma omp parallel for shared(tot)
    for (int i=0;i<N;i++)
    {
    #pragma omp atomic
        tot++;
    }

printf("Total: %d\n",tot);
}