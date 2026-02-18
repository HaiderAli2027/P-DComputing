#include <iostream>
#include <omp.h>
using namespace std;

int main()
{
    omp_set_num_threads(6);

    int shared_result = 0;

#pragma omp parallel shared(shared_result)
    {
        int thread_id = omp_get_thread_num();
        int total_threads = omp_get_num_threads();
        int num_procs = omp_get_num_procs();

#pragma omp critical
        {
            cout << "Thread ID: " << thread_id
                 << " | Total Threads: " << total_threads
                 << " | Processors: " << num_procs << endl;

            if (thread_id % 2 == 0)
            {
                shared_result += thread_id + 10;
                cout << "Thread " << thread_id << " (Even) performed Addition: "
                     << thread_id << " + 10 = " << thread_id + 10 << endl;
            }
            else
            {
                shared_result += thread_id * 10;
                cout << "Thread " << thread_id << " (Odd) performed Multiplication: "
                     << thread_id << " * 10 = " << thread_id * 10 << endl;
            }
        }
    }

    cout << "\nFinal Shared Result: " << shared_result << endl;

    return 0;
}