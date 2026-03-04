#include <iostream>
#include <omp.h>
using namespace std;

int main()
{
    int count = 0;

#pragma omp parallel for
    for (int i = 1; i <= 1000; i++)
        if (i % 2 == 0)
            count++;

    cout << "Without sync: " << count << endl;

    count = 0;
#pragma omp parallel for
    for (int i = 1; i <= 1000; i++)
    {
        if (i % 2 == 0)
        {
#pragma omp critical
            count++;
        }
    }
    cout << "Using critical: " << count << endl;

    count = 0;
#pragma omp parallel for
    for (int i = 1; i <= 1000; i++)
    {
        if (i % 2 == 0)
        {
#pragma omp atomic
            count++;
        }
    }
    cout << "Using atomic: " << count << endl;

    return 0;
}