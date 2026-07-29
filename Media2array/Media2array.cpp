// Online C++ compiler to run C++ program online
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int arr1[]{ 1,4,3,7,-4,-6,2 };
    int arr2[]{ -2,-4,1,-6,7,8,5 };
    //int arr[];

    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);
    int l = m + n;
    int arr[14];
    for (int j = 0; j < m; j++)
    {
        arr[j] = arr1[j];
    }
    int a = 0;
    for (int k = m; k < l; k++)
    {
        arr[k] = arr2[a++];
    }

    for (int i = 0; i < l; i++)
    {
        std::cout << arr[i] << std::endl;
    }
    std::cout << "__________________________________" << std::endl;
    std::cout << m << std::endl;


    sort(arr, arr + l);
    for (int i = 0; i < l; i++)
    {
        std::cout << arr[i] << std::endl;
    }
    // Write C++ code here
    std::cout << "Try programiz.pro";

    if (l % 2 == 0)
    {
        int c = l / 2;
        int d = arr[c] + arr[c - 1];

        std::cout << "meridian value" << d / 2 << std::endl;
    }
    else
    {
        int c = round(l / 2);
        int d = arr[c];
    }
    return 0;
}


