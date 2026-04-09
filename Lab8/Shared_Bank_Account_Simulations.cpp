#include <iostream>
#include <omp.h>
using namespace std;

int main()
{
    int balance = 0;

#pragma omp parallel
    {
        for (int i = 0; i < 100; i++)
        {
#pragma omp critical
            balance += 10;
        }
    }

    cout << "Final account balance: " << balance << endl;
}