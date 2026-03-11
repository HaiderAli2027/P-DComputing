#include <iostream>
#include <omp.h>
using namespace std;

int main()
{
    int sum = 0;

#pragma omp parallel for reduction(+ : sum)
    for (int i = 1; i <= 100; i++)
        sum += i;

    cout << "The sum of first 100 natural numbers in parallel is: " << sum;

    return 0;
}