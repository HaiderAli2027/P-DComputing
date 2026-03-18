#include <iostream>
#include <algorithm>
#include <omp.h>
using namespace std;

int main()
{
    int arr1[5] = {5, 2, 9, 1, 3};
    int arr2[5] = {5, 2, 9, 1, 3};

#pragma omp parallel sections
    {
#pragma omp section
        {
            sort(arr1, arr1 + 5);
        }

#pragma omp section
        {
            sort(arr2, arr2 + 5, greater<int>());
        }
    }

    cout << "Ascending: ";
    for (int i = 0; i < 5; i++)
        cout << arr1[i] << " ";
    cout << endl;

    cout << "Descending: ";
    for (int i = 0; i < 5; i++)
        cout << arr2[i] << " ";
    cout << endl;
}