// Online C++ compiler to run C++ program online
#include <iostream>
#include <limits.h>

int main() {
    // Write C++ code here
    std::cout << "Try programiz.pro";
    int arr[] = { 23,45,63,2,44,6,53 };

    int lowest = INT_MAX;
    int slowest = INT_MAX;
    int len = sizeof(arr) / sizeof(arr[0]);
    for (int i = 1; i < len; i++)
    {

        if (arr[i] < lowest)
        {

            lowest = arr[i];

        }
        else
        {
            if ((slowest > arr[i]) && (slowest > lowest))
            {
                slowest = arr[i];
            }
        }
    }


    std::cout << "lowest:" << lowest << "slowest:" << slowest;

    return 0;
}