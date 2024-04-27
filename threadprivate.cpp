#include <omp.h>
#include <stdio.h>

int myVar = 42;  // Global variable
#pragma omp threadprivate(myVar)  // Make myVar thread-private

int main() {
    #pragma omp parallel num_threads(4)
    {
        myVar += omp_get_thread_num();  // Each thread modifies myVar
        printf("Thread %d first region myVar = %d\n", omp_get_thread_num(), myVar);
    }

    // Start another parallel region
    #pragma omp parallel num_threads(4)
    {
        printf("Thread %d second region myVar = %d\n", omp_get_thread_num(), myVar);
        myVar += 5;  // Each thread further modifies myVar
    }

    // Optionally, show the effect outside of parallel region
    #pragma omp parallel num_threads(4)
    {
        printf("Thread %d third region myVar = %d\n", omp_get_thread_num(), myVar);
    }

    printf("myVar = %d, so master thread is thread 0\n", myVar);
    return 0;
}