#include <iostream>
#include <omp.h>
using namespace std;

int main()
{
    omp_set_num_threads(4);

#pragma omp parallel
    {
        int thread_id = omp_get_thread_num();

        if (thread_id == 0)
        {
            cout << "Hello from Master Thread " << thread_id << endl;
        }
    }

    return 0;
}