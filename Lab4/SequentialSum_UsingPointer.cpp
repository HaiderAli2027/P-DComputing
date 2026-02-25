#include <iostream>

int main()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    int *p = arr;
    int sum = 0;

    for (int i = 0; i < 6; i++)
    {
        sum += *(p++);
    }
    std::cout << "Sequential pointer sum of array is: " << sum << std::endl;
    return 0;
}