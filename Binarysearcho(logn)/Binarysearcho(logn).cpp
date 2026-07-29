// Binarysearcho(logn).cpp : 
// This file contains the 'main' function. 
// Program execution begins and ends there.
//

#include <iostream>

int binarysearch(int arry[], int high, int low, int k)
{
    while (low <= high)
    {
        //if (arry[low] < k)
           int  mid = low + (high - low) / 2;
           if (arry[mid] == k)
           {
               std::cout << k << "found in array" << std::endl;
               return arry[mid];
           }
           if (arry[low] < k)
               low = mid + 1;
           else
               high = mid - 1;



    }
    std::cout << k << ":was not find in array" << std::endl;
    return -1;
}
int main()
{

    int arr[] = {4,5,6,34,45,73,98,112};
    int length = sizeof(arr) / sizeof(arr[0]);
    binarysearch(arr,length,0,145);
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
