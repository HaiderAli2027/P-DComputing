#include <stdio.h>
#include <omp.h>

int main()
{
    int i, count = 0, key = 5;
    int arr[20] = {1, 5, 3, 5, 5, 6, 7, 5, 9, 0, 5, 2, 3, 4, 5, 6, 7, 8, 5, 0};

#pragma omp parallel for
    for (i = 0; i < 20; i++)
    {
        if (arr[i] == key)
        {
#pragma omp atomic
            count++;
        }
    }

    printf("Parallel Search Counter Using Atomic\n");
    printf("Element %d found %d times\n", key, count);
    return 0;
}