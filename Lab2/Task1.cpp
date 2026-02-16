#include <iostream>
using namespace std;
#include <omp.h>

int main() {

    // Set number of threads to 4
    omp_set_num_threads(4);

    // Parallel region
    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        int total_threads = omp_get_num_threads();

        #pragma omp critical
        {
            cout << "Thread ID: " << thread_id
                 << " | Total Threads: " << total_threads
                 << endl;
        }
    }

    return 0;
}
