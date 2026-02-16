#include <stdio.h>
#include <omp.h>

int main()
{
    omp_set_num_threads(3);
#pragma omp parallel sections
    {
#pragma omp section
        {
            printf("Section 1 (Thread %d)\n", omp_get_thread_num());
            for (int i = 0; i < 5; i++)
            {
                if (i % 2 == 0)
                {
                    printf("Section 1 - i = %d (Thread %d)\n", i, omp_get_thread_num());
                }
            }
        }
#pragma omp section
        {
            printf("Section 2 (Thread %d)\n", omp_get_thread_num());
            for (int j = 0; j < 5; j++)
            {
                if (j % 2 == 0)
                {
                    printf("Section 2 - j = %d (Thread %d)\n", j, omp_get_thread_num());
                }
            }
        }
#pragma omp section
        {
            printf("Section 3 (Thread %d)\n", omp_get_thread_num());
            for (int k = 0; k < 5; k++)
            {
                if (k % 2 == 0)
                {
                    printf("Section 3 - k = %d (Thread %d)\n", k, omp_get_thread_num());
                }
            }
        }
    }
}