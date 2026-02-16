#include <iostream>
using namespace std;
#include <omp.h>

int factorial(int n) {
    int fact = 1;
    for(int i = 1; i <= n; i++)
        fact *= i;
    return fact;
}

int main() {

    int a = 5, b = 3;

    // Set number of threads
    omp_set_num_threads(4);

    #pragma omp parallel
    {
        #pragma omp sections
        {
            #pragma omp section
            {
                int sum = a + b;
                cout << "Thread " << omp_get_thread_num()
                     << " performing Addition: " << sum << endl;
            }

            #pragma omp section
            {
                int product = a * b;
                cout << "Thread " << omp_get_thread_num()
                     << " performing Multiplication: " << product << endl;
            }

            #pragma omp section
            {
                int fact = factorial(a);
                cout << "Thread " << omp_get_thread_num()
                     << " performing Factorial of " << a << ": " << fact << endl;
            }
        } 
    } 

    return 0;
}

