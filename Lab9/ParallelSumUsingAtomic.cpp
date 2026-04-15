#include <stdio.h>
#include <omp.h>

int main()
{
    int i, sum = 0;
    int arr[20];
    for (i = 0; i < 20; i++)
        arr[i] = i + 1;

#pragma omp parallel for
    for (i = 0; i < 20; i++)
    {
#pragma omp atomic
        sum += arr[i];
    }

    printf("Parallel Sum Using Atomic\n");
    printf("Total Sum = %d\n", sum);
    return 0;
}