#include <iostream>
#include <omp.h>
using namespace std;

int main()
{
    int n = 2;

#pragma omp parallel if (n > 4)
    {
        cout << "Thread " << omp_get_thread_num() << " is executing." << endl;
    }

    return 0;
}
