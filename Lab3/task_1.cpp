#include <iostream>
#include <omp.h>
using namespace std;

int main()
{
    omp_set_num_threads(4);

#pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        int total = omp_get_num_threads();

#pragma omp critical
        {
            cout << "Hello World from Thread " << thread_id
                 << " of " << total << " threads" << endl;
        }
    }

    return 0;
}