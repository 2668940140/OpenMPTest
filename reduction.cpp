#include <cstdio>
#define N 1000
int A[N];
int tot;
int main()
{
    for(int i=0;i<N;i++) A[i]=i+1;

#pragma omp parallel for reduction(+:tot)
    for(int i=0;i<N;i++)
        tot+=A[i];

    printf("Total:%d\n",tot);
}