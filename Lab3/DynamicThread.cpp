#include <iostream>
#include <omp.h>
using namespace std;

int main()
{

    omp_set_dynamic(1); // Enable dynamic adjustment of threads
    omp_set_num_threads(8);
#pragma omp parallel
    {
#pragma omp single
        {
            int num_threads = omp_get_num_threads();
            cout << "Number of threads in this parallel region: " << num_threads << endl;
        }
    }
    return 0;
}