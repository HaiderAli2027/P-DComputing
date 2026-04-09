#include <iostream>
#include <omp.h>
using namespace std;

int main()
{
    int n = 10;
    long long result = 1;

#pragma omp parallel for
    for (int i = 1; i <= n; i++)
    {
#pragma omp critical
        result *= i;
    }

    cout << "Factorial of " << n << " is: " << result << endl;
}