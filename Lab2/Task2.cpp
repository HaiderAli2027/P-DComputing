#include <iostream>
#include <omp.h>
using namespace std;

int main()
{

   int counter = 0;

   omp_set_num_threads(4);

#pragma omp parallel
   {
      counter++;
   }

   cout << "Final Counter Value: " << counter << endl;

   return 0;
}