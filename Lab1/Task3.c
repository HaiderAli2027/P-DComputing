#include <stdio.h>
#include <omp.h>

int main()
{
    omp_set_num_threads(1);
#pragma omp parallel
    {
        int val1;
        int val2;

        printf("Enter first number: ");
        scanf("%d", &val1);
        printf("Enter second number: ");
        scanf("%d", &val2);
        int sum = val1 + val2;
        printf("Sum of numbers is: %d\n", sum);
    }
}