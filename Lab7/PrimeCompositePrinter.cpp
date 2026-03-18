#include <iostream>
#include <omp.h>
using namespace std;

bool isPrime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

int main()
{
    string primes = "", composites = "";

#pragma omp parallel sections
    {
#pragma omp section
        {
            for (int i = 2; i <= 50; i++)
                if (isPrime(i))
                    primes += to_string(i) + " ";
        }

#pragma omp section
        {
            for (int i = 2; i <= 50; i++)
                if (!isPrime(i))
                    composites += to_string(i) + " ";
        }
    }

    cout << "Primes: " << primes << endl;
    cout << "Composites: " << composites << endl;
}