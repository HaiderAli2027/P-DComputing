#include <iostream>
#include <omp.h>
using namespace std;

int main()
{
    int n = 10;
    int sum = 0;

#pragma omp parallel for reduction(+ : sum)
    for (int i = 1; i <= n; i++)
        sum += i * i;

    cout << "The sum of squares of first " << n << " natural numbers in parallel is: " << sum;

    return 0;
}