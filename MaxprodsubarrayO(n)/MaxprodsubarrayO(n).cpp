// MaxprodsubarrayO(n).cpp : This file contains the 'main' function. Program execution begins and ends there.

// I/p { -2, 6, -3, -10, 0, 2 };
// o/p 180
// Timecomplexity O(n)
// 
// 
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
    int arr[] = { -2, 6, -3, -10, 0, 2 };

    int size = sizeof(arr) / sizeof(arr[0]);
    int maxprod = 0;
    int RighttoLeft = 1;
    int LefttoRight = 1;
    for (int i = 0; i < size; i++)
    {
        if (RighttoLeft == 0)
            RighttoLeft = 1;
        if (LefttoRight == 0)
            LefttoRight = 1;
        LefttoRight = LefttoRight * arr[i];
        int j = size - i - 1;
        RighttoLeft = RighttoLeft * arr[j];
        // maxprod = max({RighttoLeft,LefttoRight,maxprod});
        maxprod = std::max({ LefttoRight, RighttoLeft, maxprod });

        std::cout << "Max prod subarray" << maxprod << std::endl;
    }

    return 0;

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
