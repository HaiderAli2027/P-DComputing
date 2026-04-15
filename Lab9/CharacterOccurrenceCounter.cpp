#include <stdio.h>
#include <omp.h>
#include <string.h>

int main()
{
    char str[] = "helloopenmp";
    int freq[256] = {0};
    int i, n = strlen(str);

#pragma omp parallel for
    for (i = 0; i < n; i++)
    {
#pragma omp atomic
        freq[(int)str[i]]++;
    }

    printf("Character Occurrence Counter Using Atomic\n");
    for (i = 0; i < 256; i++)
        if (freq[i] > 0)
            printf("%c = %d\n", i, freq[i]);

    return 0;
}