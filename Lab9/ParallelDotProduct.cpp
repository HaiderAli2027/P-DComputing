#include <stdio.h>
#include <omp.h>

int main()
{
    int i, sum = 0;
    int a[5] = {1, 2, 3, 4, 5};
    int b[5] = {5, 4, 3, 2, 1};

#pragma omp parallel for
    for (i = 0; i < 5; i++)
    {
#pragma omp atomic
        sum += a[i] * b[i];
    }

    printf("Parallel Dot Product Using Atomic\n");
    printf("Dot Product = %d\n", sum);
    return 0;
}