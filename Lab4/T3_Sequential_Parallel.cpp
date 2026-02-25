#include <iostream>
#include <omp.h>

using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int n = 15;
    int sum = 0;
    double start, end;

    start = omp_get_wtime();
    for (int i = 0; i < n; i++)
        sum += arr[i];
    end = omp_get_wtime();
    cout << "Sequential Sum = " << sum << endl;
    cout << "Sequential Time = " << end - start << endl;

    sum = 0;

    start = omp_get_wtime();
#pragma omp parallel for reduction(+ : sum)
    for (int i = 0; i < n; i++)
        sum += arr[i];
    end = omp_get_wtime();
    cout << "Parallel Sum = " << sum << endl;
    cout << "Parallel Time = " << end - start << endl;

    return 0;
}