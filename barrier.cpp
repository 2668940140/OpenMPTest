#include <omp.h>
#include <cstdio>
#include <chrono>


int main()
{
#pragma omp parallel
{
    printf("Phase1\n");
    printf("Phase2\n");
}

printf("\n\n\n*********************\n");
#pragma omp parallel
{
    printf("Phase1\n");
    #pragma omp barrier
    printf("Phase2\n");
}
}