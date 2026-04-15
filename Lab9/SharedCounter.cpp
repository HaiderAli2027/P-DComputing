#include <stdio.h>
#include <omp.h>

int main()
{
    int i, counter = 0;

#pragma omp parallel for
    for (i = 0; i < 100; i++)
    {
#pragma omp atomic
        counter++;
    }

    printf("Shared Counter Increment with Atomic\n");
    printf("Final Counter Value = %d\n", counter);
    return 0;
}