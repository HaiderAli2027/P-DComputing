#include <iostream>
#include <omp.h>
using namespace std;

int main()
{
    int counter;
    double start,end;

    counter=0;
    start=omp_get_wtime();
    #pragma omp parallel for
    for(int i=0;i<100000;i++)
        counter++;
    end=omp_get_wtime();
    cout<<"Without synchronization: "<<counter<<endl;
    cout<<"Time: "<<end-start<<endl;

    counter=0;
    start=omp_get_wtime();
    #pragma omp parallel for
    for(int i=0;i<100000;i++)
    {
        #pragma omp critical
        counter++;
    }
    end=omp_get_wtime();
    cout<<"Using critical: "<<counter<<endl;
    cout<<"Time: "<<end-start<<endl;

    counter=0;
    start=omp_get_wtime();
    #pragma omp parallel for
    for(int i=0;i<100000;i++)
    {
        #pragma omp atomic
        counter++;
    }
    end=omp_get_wtime();
    cout<<"Using atomic: "<<counter<<endl;
    cout<<"Time: "<<end-start<<endl;

    return 0;
}