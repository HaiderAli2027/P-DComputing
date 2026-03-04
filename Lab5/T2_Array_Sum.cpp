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
        sum += arr[i];
    cout << "Shared variable sum: " << sum << endl;

    sum = 0;
#pragma omp parallel
    {
        int local = 0;
#pragma omp for
        for (int i = 0; i < 1000; i++)
            local += arr[i];

#pragma omp critical
        sum += local;
    }
    cout << "Private with critical sum: " << sum << endl;

    sum = 0;
#pragma omp parallel for reduction(+ : sum)
    for (int i = 0; i < 1000; i++)
        sum += arr[i];

    cout << "Reduction sum: " << sum << endl;

    return 0;
}