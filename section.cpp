#include <stdio.h>
#include <omp.h>

int main() {
    #pragma omp parallel
    {
        #pragma omp single
        {
            printf("Num threads %d\n", omp_get_num_threads());
        }
        #pragma omp sections
        {
            #pragma omp section
            {
                printf("Section 1 running on thread %d\n", omp_get_thread_num());
            }
            #pragma omp section
            {
                printf("Section 2 running on thread %d\n", omp_get_thread_num());
            }
        }
    }
    return 0;
}
