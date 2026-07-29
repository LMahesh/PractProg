// Online C++ compiler to run C++ program online
#include <iostream>
#include <array>

using namespace std;

int funchk(int arr1[], int len)
{
    int m = 0;
    int l = 0;
    for (int j = 0; j < len; j++)
    {
        for (int k = 0; k < len-j-1; k++)
        {
            if ((arr1[j] == arr1[k]) && j != k)
            {
                m = m + 1;
                //std::cout << "m:" << m << std::endl;
                //std::cout << "len/2 value" << len / 2 << std::endl;
                if (m >= len / 2)
                {
                    l = arr1[j];
                    return l;
                }

            }

        }
        //turn 0;
    }
    std::cout << "length:" << len << std::endl;
    return l;
}
int main() {
    // Write C++ code here
    std::cout << "Try programiz.pro" << std::endl;
    int arr1[]{ 1,4,0,4,4,6,2,4 };
    int len = sizeof(arr1) / sizeof(arr1[0]);
    int a = funchk(arr1, len);
    std::cout <<"len:" << len << "num::" << a << std::endl;
    return 0;
}