#include <iostream>
#include <omp.h>
using namespace std;

int main()
{
    int matrix[5][5];
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            matrix[i][j] = 1;

    int sum = 0;

#pragma omp parallel for collapse(2)
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
#pragma omp critical
            sum += matrix[i][j];
        }
    }

    cout << "Sum of all matrix elements: " << sum << endl;
}