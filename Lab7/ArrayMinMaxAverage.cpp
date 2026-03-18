#include <iostream>
#include <omp.h>
using namespace std;

int main()
{
    int arr[5] = {4, 7, 1, 9, 3};

    int minVal, maxVal;
    double avg;

#pragma omp parallel sections
    {
#pragma omp section
        {
            int minTemp = arr[0];
            for (int i = 0; i < 5; i++)
                if (arr[i] < minTemp)
                    minTemp = arr[i];
            minVal = minTemp;
        }

#pragma omp section
        {
            int maxTemp = arr[0];
            for (int i = 0; i < 5; i++)
                if (arr[i] > maxTemp)
                    maxTemp = arr[i];
            maxVal = maxTemp;
        }

#pragma omp section
        {
            int sum = 0;
            for (int i = 0; i < 5; i++)
                sum += arr[i];
            avg = sum / 5.0;
        }
    }

    cout << "Min: " << minVal << endl;
    cout << "Max: " << maxVal << endl;
    cout << "Average: " << avg << endl;
}