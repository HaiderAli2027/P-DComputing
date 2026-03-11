#include <iostream>
#include <omp.h>
using namespace std;

int main()
{
    int n = 5;
    long long fact = 1;

#pragma omp parallel for reduction(* : fact)
    for (int i = 1; i <= n; i++)
        fact *= i;

    cout << "Factorial of " << n << " in parallel is: " << fact;

    return 0;
}