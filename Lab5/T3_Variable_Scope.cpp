#include <iostream>
#include <omp.h>
using namespace std;

int main()
{
    int x = 10;

#pragma omp parallel private(x)
    {
        x = 5;
        cout << "Private x inside: " << x << endl;
    }
    cout << "Outside after private: " << x << endl;

#pragma omp parallel firstprivate(x)
    {
        cout << "First private x inside: " << x << endl;
    }
    cout << "Outside after first private: " << x << endl;

#pragma omp parallel for lastprivate(x)
    for (int i = 0; i < 4; i++)
    {
        x = i;
    }

    cout << "Outside after last private: " << x << endl;

    return 0;
}