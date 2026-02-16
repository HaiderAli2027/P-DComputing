#include <stdio.h>
#include <omp.h>

int main()

{
    omp_set_num_threads(10);
#pragma omp parallel
    {
        for (int i = 0; i < 5; i++)
        {
            int id = omp_get_thread_num();
            printf("Thread %d is working on iteration %d\n", id, i);
        }
    }
    return 0;
}
