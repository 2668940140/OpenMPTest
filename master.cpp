#include <omp.h>
#include <cstdio>
#include <chrono>


int main()
{

#pragma omp parallel
{
    #pragma omp master
    {
        printf("Here is from master thread %d\n", omp_get_thread_num());
        printf("I have %d sons.\n", omp_get_num_threads() - 1);
    }

    if (omp_get_thread_num() != 0)
    printf("Here is a subthread %d\n", omp_get_thread_num());
}
}