#include <iostream>
#include <omp.h>
using namespace std;

int main()
{
    int arr[1000];
    int hist[10] = {0};

    for (int i = 0; i < 1000; i++)
        arr[i] = i % 10;

#pragma omp parallel for
    for (int i = 0; i < 1000; i++)
    {
        int index = arr[i];
#pragma omp critical
        hist[index]++;
    }

    cout << "Histogram values: ";
    for (int i = 0; i < 10; i++)
        cout << hist[i] << " ";
}