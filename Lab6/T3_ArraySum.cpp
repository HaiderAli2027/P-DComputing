#include <iostream>
#include <omp.h>
using namespace std;

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int sum = 0;

#pragma omp parallel for reduction(+ : sum)
    for (int i = 0; i < 5; i++)
        sum += arr[i];

    cout << "The sum of the array elements in parallel is: " << sum;

    return 0;
}