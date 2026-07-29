// Removeduplicates0(n).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
using namespace std;

void removeduplicates(int arr1[], int len)
{
    std::unordered_map<long long, int>frequmap1;
    for (int i = 0; i < len; i++)
    {
        frequmap1[arr1[i]]++;
    }
    for (auto i : frequmap1)
    {
        if (i.second > 1)
            //std::cout << i.first << " "<<i.second<<std::endl;
            std::cout << i.first << " " << std::endl;
    }

}
int main()
{
    int arr[] = { 1,3,6,1,2,4,2,3 };
    int len = sizeof(arr) / sizeof(arr[0]);
    removeduplicates(arr, len);
    std::cout << "----------------------------------------" << std::endl;
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (arr[i] == arr[j])
                std::cout << arr[i] << std::endl;
        }
    }
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
