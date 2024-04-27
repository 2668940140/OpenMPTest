#include <omp.h>
#include <iostream>
#include <chrono>

using namespace std::chrono;
#define N 100000000
#define chunk 1000

int a[N], b[N],c[N];


int main()
{
    omp_set_num_threads(64);
    //load in cache
    for (int i = 0;i < N; i++)
    {
        a[i] = b[i] = i;
        c[i] = a[i] + b[i];
    }


    high_resolution_clock clk;
    auto begin_time = clk.now();

    for (int i = 0;i < N; i++)
    {
        c[i] = a[i] + b[i];
    }

    auto end_time = clk.now();
    std::cout << duration_cast<milliseconds>(end_time - begin_time).count() << " ms" << std::endl;


    begin_time = clk.now();

    int num_threads;

#pragma omp parallel shared(a,b,c)
{
    #pragma omp single
    {
        num_threads = omp_get_num_threads();
    }
    #pragma omp for schedule(static,chunk)
    for (int i = 0;i < N; i++)
    {
        c[i] = a[i] + b[i];
    }
}


    end_time = clk.now();
    std::cout << duration_cast<milliseconds>(end_time - begin_time).count() << " ms" << std::endl;
    std::cout << "num_threads: " << num_threads << std::endl;


}