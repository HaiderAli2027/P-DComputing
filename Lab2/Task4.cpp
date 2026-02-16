#include <iostream>
using namespace std;
#include <omp.h>

int main() {

   int  array[10] ;

for (int i = 0; i < 10; i++) {
        array[i] = i + 1;
    }
    // Parallel region
    #pragma omp parallel 
    
       
       for (int i = 0; i < 10; i++) {

        int thread_id = omp_get_thread_num();

        array[i] = array[i] * 2;
    
    #pragma omp critical
        {
            cout << "Thread " << thread_id
                 << " processed index " << i
                 << " new value = " << array[i]
                 << endl;
        }
    }
    return 0;

}


