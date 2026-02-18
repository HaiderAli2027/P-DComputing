#include <iostream>
#include <omp.h>
using namespace std;

int main()
{
    omp_set_num_threads(4);

#pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        int total_threads = omp_get_num_threads();
        int num_procs = omp_get_num_procs();

#pragma omp critical
        {
            cout << "Thread ID: " << thread_id
                 << " | Total Threads: " << total_threads
                 << " | Number of Processors: " << num_procs << endl;
        }
    }

    return 0;
}