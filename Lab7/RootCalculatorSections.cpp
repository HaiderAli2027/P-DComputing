#include <iostream>
#include <cmath>
#include <omp.h>
using namespace std;

int main()
{
    string sq = "", cb = "";

#pragma omp parallel sections
    {
#pragma omp section
        {
            for (int i = 1; i <= 10; i++)
                sq += to_string(sqrt(i)) + " ";
        }

#pragma omp section
        {
            for (int i = 1; i <= 10; i++)
                cb += to_string(cbrt(i)) + " ";
        }
    }

    cout << "Square Roots: " << sq << endl;
    cout << "Cube Roots: " << cb << endl;
}