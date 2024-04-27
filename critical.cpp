#include <omp.h>
#include <iostream>
#include <chrono>

void critical_segment()
{
    std::cout<<0<<1<<2<<3<<4<<5<<6<<7<<8<<9<<std::endl;
}


int main()
{
#pragma omp parallel for
    for(int i=0;i<10;i++)
        critical_segment();

std::cout<<"\n\n\n*********************\n";

#pragma omp parallel for
    for(int i=0;i<10;i++)
    {
    #pragma omp critical
        critical_segment();
    }
}