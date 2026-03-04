#include <iostream>
#include <omp.h>
#include <cstdlib>
using namespace std;

int main()
{
    int arr[5000];
    for (int i = 0; i < 5000; i++)
        arr[i] = rand() % 100;

    double sum = 0;

#pragma omp parallel for
    for (int i = 0; i < 5000; i++)
        sum += arr[i];

    cout << "Shared sum: " << sum << endl;
    cout << "Average: " << sum / 5000 << endl;

    sum = 0;

#pragma omp parallel for reduction(+ : sum)
    for (int i = 0; i < 5000; i++)
        sum += arr[i];

    cout << "Reduction sum: " << sum << endl;
    cout << "Average: " << sum / 5000 << endl;

    return 0;
}