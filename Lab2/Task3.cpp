#include <iostream>
using namespace std;
#include <omp.h>

int main()
{

    int x = 0;

    cout << "Before Parllel region: " << x << endl;

// Parallel region
#pragma omp parallel private(x)
    {

        x = 50;

#pragma omp critical
        {
            cout << "Inside the region (Thread "
                 << omp_get_thread_num()
                 << "), x = " << x << endl;
        }
    }

    cout << "After the region: " << x << endl;
    return 0;
}
