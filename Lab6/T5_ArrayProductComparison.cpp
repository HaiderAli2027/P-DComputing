#include <iostream>
#include <omp.h>
using namespace std;

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    long long seq = 1;
    long long par = 1;

    for (int i = 0; i < 5; i++)
        seq *= arr[i];

#pragma omp parallel for reduction(* : par)
    for (int i = 0; i < 5; i++)
        par *= arr[i];

    cout << "Sequential product: " << seq << endl;
    cout << "Parallel product: " << par << endl;

    return 0;
}