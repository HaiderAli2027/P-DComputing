#include <iostream>
using namespace std;
#include <omp.h>

int main() {

   int  counter =0 ;
    omp_set_num_threads(4);

    // Parallel region
    #pragma omp parallel
    {
       counter++ ;
       
        
            cout<<"Print final value :"<<counter<<endl;
        
    }

    return 0;
}

