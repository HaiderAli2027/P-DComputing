#include <iostream>
#include <omp.h>
using namespace std;

int main()
{

    int p = omp_get_num_procs();
    omp_set_num_threads(p);
#pragma omp parallel
    {
        cout << "Thread " << omp_get_thread_num() << " is executing." << endl;
    }
    return 0;
}