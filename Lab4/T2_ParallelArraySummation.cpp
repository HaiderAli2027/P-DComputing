#include <iostream>
#include <omp.h>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = 7;
    int sum = 0;

#pragma omp parallel for reduction(+ : sum)
    for (int i = 0; i < n; i++)
        sum += arr[i];

    cout << "Sum = " << sum << endl;
    return 0;
}