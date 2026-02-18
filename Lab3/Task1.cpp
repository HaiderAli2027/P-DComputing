#include <iostream>
#include <omp.h>
using namespace std;

int main()
{
    int num_threads = omp_get_max_threads();
    cout << "Number of threads: " << num_threads << endl;

    return 0;
}
