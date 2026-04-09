#include <iostream>
#include <omp.h>
using namespace std;

int main()
{
    int arr[1000];
    for (int i = 0; i < 1000; i++)
        arr[i] = 1;

    int sum = 0;

#pragma omp parallel for
    for (int i = 0; i < 1000; i++)
    {
#pragma omp critical
        sum += arr[i];
    }

    cout << "Sum of array elements: " << sum << endl;
}