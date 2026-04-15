#include <stdio.h>
#include <omp.h>

int main()
{
    int i, sum1 = 0, sum2 = 0;
    int arr[100000];
    for (i = 0; i < 100000; i++)
        arr[i] = 1;

    double t1 = omp_get_wtime();
#pragma omp parallel for
    for (i = 0; i < 100000; i++)
    {
#pragma omp atomic
        sum1 += arr[i];
    }
    double t2 = omp_get_wtime();

    double t3 = omp_get_wtime();
#pragma omp parallel for
    for (i = 0; i < 100000; i++)
    {
#pragma omp critical
        sum2 += arr[i];
    }
    double t4 = omp_get_wtime();

    printf("Atomic vs Critical Performance Comparison\n");
    printf("Atomic Sum = %d Time = %f\n", sum1, t2 - t1);
    printf("Critical Sum = %d Time = %f\n", sum2, t4 - t3);

    return 0;
}