#include <omp.h>
#include <iostream>
#include <chrono>
#include <cassert>

using namespace std::chrono;

int fib(int n)
{
    return n <= 2 ? 1 : fib(n - 1) + fib(n - 2);
}

int fib_par(int n)
{
    if (n <= 2) return 1;


    if (n <= 40) return fib(n);
    else
    {
    int i,j;
    #pragma omp task shared(i) firstprivate(n)
    i = fib_par(n - 1);
    #pragma omp task shared(j) firstprivate(n)
    j = fib_par(n - 2);

    #pragma omp taskwait
    return i+j;
    }
}



int main()
{
    int ans[2];
    high_resolution_clock clk;
    auto begin_time = clk.now();
    ans[0] = fib(42);
    auto end_time = clk.now();
    std::cout << duration_cast<milliseconds>(end_time - begin_time).count() << " ms" << std::endl;

    begin_time = clk.now();
    ans[1] = fib_par(42);
    end_time = clk.now();
    std::cout << duration_cast<milliseconds>(end_time - begin_time).count() << " ms" << std::endl;

    assert(ans[0] == ans[1]);
}