#include <iostream>
#include <omp.h>
#include <string>
using namespace std;

int main()
{
    string result = "";

#pragma omp parallel
    {
        string local = "A";
#pragma omp critical
        result += local;
    }

    cout << "Final concatenated string: " << result << endl;
}