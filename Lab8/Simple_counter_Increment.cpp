#include <iostream>
#include <omp.h>
using namespace std;

int main()
{
    int counter = 0;

#pragma omp parallel
    {
        for (int i = 0; i < 1000; i++)
        {
            counter++;
        }
    }

    cout << "Counter without critical section: " << counter << endl;

    counter = 0;

#pragma omp parallel
    {
        for (int i = 0; i < 1000; i++)
        {
#pragma omp critical
            counter++;
        }
    }

    cout << "Counter with critical section: " << counter << endl;
}