#include <stdio.h>
#include <omp.h>

int main()
{
    int i, max = 0, element = -1;
    int arr[20] = {1, 2, 3, 2, 4, 2, 5, 2, 6, 2, 7, 8, 2, 9, 2, 0, 2, 3, 2, 4};
    int freq[10] = {0};

#pragma omp parallel for
    for (i = 0; i < 20; i++)
    {
#pragma omp atomic
        freq[arr[i]]++;
    }

    for (i = 0; i < 10; i++)
    {
        if (freq[i] > max)
        {
            max = freq[i];
            element = i;
        }
    }

    printf("Maximum Frequency Element Using Atomic\n");
    printf("Element = %d Frequency = %d\n", element, max);
    return 0;
}