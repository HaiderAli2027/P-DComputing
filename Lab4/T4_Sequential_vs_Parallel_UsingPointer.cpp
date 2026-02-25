#include <iostream>
#include <omp.h>
using namespace std;

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80};
    int n = 8;
    int seqSum = 0, parSum = 0;

    int *p = arr;
    for (int i = 0; i < n; i++)
        seqSum += *(p++);

#pragma omp parallel for reduction(+ : parSum)
    for (int i = 0; i < n; i++)
        parSum += arr[i];

    cout << "Sequential Sum = " << seqSum << endl;
    cout << "Parallel Sum   = " << parSum << endl;

    if (seqSum == parSum)
        cout << "Both sums match!" << endl;
    else
        cout << "Sums do not match!" << endl;

    return 0;
}