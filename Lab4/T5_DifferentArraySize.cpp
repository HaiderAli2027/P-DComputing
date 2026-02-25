#include <iostream>
#include <omp.h>
using namespace std;

void compute(int arr[], int n, string label)
{
    int sum = 0;
    double start, end;

    start = omp_get_wtime();
    for (int i = 0; i < n; i++)
        sum += arr[i];
    end = omp_get_wtime();
    cout << label << " Sequential Sum = " << sum << " Time = " << end - start << endl;

    sum = 0;
    start = omp_get_wtime();
#pragma omp parallel for reduction(+ : sum)
    for (int i = 0; i < n; i++)
        sum += arr[i];
    end = omp_get_wtime();
    cout << label << " Parallel Sum   = " << sum << " Time = " << end - start << endl;
}

int main()
{
    int a4[] = {1, 2, 3, 4};
    int a8[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int a12[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int a20[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

    compute(a4, 4, "Size 4 :");
    compute(a8, 8, "Size 8 :");
    compute(a12, 12, "Size 12:");
    compute(a20, 20, "Size 20:");

    return 0;
}