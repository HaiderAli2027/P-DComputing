#include <iostream>
#include <omp.h>
using namespace std;

int main()
{
    int tickets = 100;

#pragma omp parallel
    {
        for (int i = 0; i < 20; i++)
        {
#pragma omp critical
            if (tickets > 0)
            {
                tickets--;
            }
        }
    }

    cout << "Remaining tickets after booking: " << tickets << endl;
}