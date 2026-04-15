#include <stdio.h>
#include <omp.h>

int main()
{
    int i, even = 0, odd = 0;
    int arr[20];
    for (i = 0; i < 20; i++)
        arr[i] = i;

#pragma omp parallel for
    for (i = 0; i < 20; i++)
    {
        if (arr[i] % 2 == 0)
        {
#pragma omp atomic
            even++;
        }
        else
        {
#pragma omp atomic
            odd++;
        }
    }

    printf("Odd and Even Counter Using Atomic\n");
    printf("Even Count = %d\n", even);
    printf("Odd Count = %d\n", odd);
    return 0;
}