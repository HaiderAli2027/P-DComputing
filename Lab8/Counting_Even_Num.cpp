#include <iostream>
#include <omp.h>
using namespace std;

int main()
{
    int arr[1000];
    for (int i = 0; i < 1000; i++)
        arr[i] = i;

    int count = 0;

#pragma omp parallel for
    for (int i = 0; i < 1000; i++)
    {
        if (arr[i] % 2 == 0)
        {
#pragma omp critical
            count++;
        }
    }

    cout << "Total even numbers in array: " << count << endl;
}