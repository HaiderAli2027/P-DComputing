#include <stdio.h>
#include <omp.h>

int main()
{
    int i;
    int arr[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int freq[10] = {0};

#pragma omp parallel for
    for (i = 0; i < 20; i++)
    {
#pragma omp atomic
        freq[arr[i]]++;
    }

    printf("Frequency Counter for Digits 0 to 9\n");
    for (i = 0; i < 10; i++)
        printf("Digit %d = %d\n", i, freq[i]);

    return 0;
}