#include <stdio.h>
#include <omp.h>

int main()
{
    omp_set_num_threads(1);
#pragma omp parallel
    {
        int val1 = 10;
        int val2 = 20;
        int sum = val1 + val2;
        printf("Sum of numbers is: %d\n", sum);
    }
    return 0;
}
