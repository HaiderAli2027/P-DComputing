#include <stdio.h>
#include <omp.h>

int main()
{
    int i, count = 0;
    int arr[20];
    for (i = 0; i < 20; i++)
        arr[i] = i;

#pragma omp parallel for
    for (i = 0; i < 20; i++)
    {
        if (arr[i] % 2 == 0)
        {
#pragma omp atomic
            count++;
        }
    }

    printf("Even Number Counter Using Atomic\n");
    printf("Even Numbers Count = %d\n", count);
    return 0;
}