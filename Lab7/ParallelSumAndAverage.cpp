#include <iostream>
#include <omp.h>
using namespace std;

int main()
{
    int sum = 0;
    double avg = 0;

#pragma omp parallel sections
    {
#pragma omp section
        {
            int s = 0;
            for (int i = 1; i <= 100; i++)
                s += i;
            sum = s;
        }

#pragma omp section
        {
            int s = 0;
            for (int i = 1; i <= 100; i++)
                s += i;
            avg = s / 100.0;
        }
    }

    cout << "Sum: " << sum << endl;
    cout << "Average: " << avg << endl;
}