#include <iostream>

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int sum = 0;

    for (int i = 0; i < 5; i++)
    {
        sum += arr[i];
    }

    std::cout << "Sequential Sum Of array is: " << sum << std::endl;
    return 0;
}