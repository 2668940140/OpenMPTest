#include <cstdio>


#define N 10000
int main()
{
    int a=0,b=0;
#pragma omp parallel for private(a) shared(b)
    for (int i=0;i<N;i++)
    {
    #pragma omp atomic
        a++;
    #pragma omp atomic
        b++;
    }

    printf("a:%d\nb:%d\n",a,b);

    a=b=0;
#pragma omp parallel for lastprivate(a) firstprivate(b)
    for (int i=0;i<N;i++)
    {
    #pragma omp atomic
        a++;
    #pragma omp atomic
        b++;
    }
    printf("a:%d\nb:%d\n",a,b);
}