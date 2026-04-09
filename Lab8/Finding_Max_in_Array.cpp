#include <iostream>
#include <omp.h>
using namespace std;

int main()
{
    int arr[1000];
    for (int i = 0; i < 1000; i++)
        arr[i] = i;

    int max_val = arr[0];

#pragma omp parallel for
    for (int i = 0; i < 1000; i++)
    {
#pragma omp critical
        if (arr[i] > max_val)
            max_val = arr[i];
    }

    cout << "Maximum value in array: " << max_val << endl;
}